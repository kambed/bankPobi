#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <string>
#include "functions.h"

std::string dateTimeToString(boost::posix_time::ptime dateTime){
    std::stringstream ss;
    ss << dateTime;
    std::string stringDateTime = ss.str();
    return stringDateTime;
}

std::string nowString() {
    return dateTimeToString(boost::posix_time::second_clock::local_time());
}
