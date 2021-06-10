#include "model/TurboLogger.h"
#include <exceptions/TurboLoggerException.h>
#include "functions.h"

TurboLogger::TurboLogger() {
    std::system("mkdir -p ./logs");
    do {
        int i=0;
        fileName = "logs/logs_" + nowFileName() +std::to_string(i)+ ".txt";
    }while(fileExists(fileName));
    logs.open(fileName, std::ofstream::out | std::ofstream::app);
    if (logs.is_open()) {
        logs << "Logs file, created at: " + nowString() + "\n";
        logs.close();
    } else {
        throw TurboLoggerException("Can not create file");
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
