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

std::string nowFileName(){
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    std::string now_string = std::to_string(now.date().day())+"."+
                             std::to_string(now.date().month().as_number())+"."+
                             std::to_string(now.date().year())+"_"+
                             std::to_string(now.time_of_day().hours())+"."+
                             std::to_string(now.time_of_day().minutes())+"."+
                             std::to_string(now.time_of_day().seconds())+"."+
                             std::to_string(now.time_of_day().total_microseconds()).substr(0,2);
    return now_string;
}