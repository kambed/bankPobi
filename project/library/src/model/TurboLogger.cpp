#include "model/TurboLogger.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <fstream>
#include "functions.h"

TurboLogger::TurboLogger() {
    fileName = "logs_"+nowFileName()+".txt";
    logs.open(fileName, std::ofstream::out | std::ofstream::app);
    if(logs.is_open()) {
        logs << "Logs file, created at: " + nowString() + "\n";
        logs.close();
    }else{
        //throw extension
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
