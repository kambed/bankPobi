#include "model/TurboLogger.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <fstream>
#include <exceptions/TurboLoggerException.h>
#include "functions.h"

TurboLogger::TurboLogger() {
    do {
        int i=0;
        fileName = "logs_" + nowFileName() +std::to_string(i)+ ".txt";
    }while(fileExists(fileName));
    try {
        logs.open(fileName, std::ofstream::out | std::ofstream::app);
        if (logs.is_open()) {
            logs << "Logs file, created at: " + nowString() + "\n";
            logs.close();
        } else {
            throw TurboLoggerException("Can not create file");
        }
    }catch(const TurboLoggerException &exception){
        std::cout << "Exception: " << exception.what() << std::endl;
    }
}

bool TurboLogger::addLog(std::string whatToLog) {
    std::string log = nowString()+"   "+whatToLog+"\n";
    logs.open(fileName, std::ofstream::out | std::ofstream::app);
    if(logs.is_open()) {
        logs << log;
        logs.close();
        return true;
    }else{
        return false;
    }
}

const std::string &TurboLogger::getFileName() const {
    return fileName;
}
