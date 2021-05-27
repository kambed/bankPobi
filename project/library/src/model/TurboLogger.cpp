#include "model/TurboLogger.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <fstream>

TurboLogger::TurboLogger() {}

void TurboLogger::addLog(std::string whatToLog) {
    std::stringstream ss;
    ss << boost::posix_time::second_clock::local_time();
    std::string now= ss.str();
    std::string log = now+"   "+whatToLog;

    std::ofstream logi;
    logi.open("logi.txt", std::ofstream::out | std::ofstream::app);
    logi<<log;
    logi.close();
}
