#include "model/TurboLogger.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <fstream>

TurboLogger::TurboLogger() {}

bool TurboLogger::addLog(std::string whatToLog) {
    std::stringstream ss;
    ss << boost::posix_time::second_clock::local_time();
    std::string now= ss.str();
    std::string log = now+"   "+whatToLog+"\n";

    std::ofstream logs;
    logs.open("logs.txt", std::ofstream::out | std::ofstream::app);
    if(logs.is_open()) {
        logs << log;
        logs.close();
        return true;
    }else{
        return false;
    }
}
