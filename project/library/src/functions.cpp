#include <boost/date_time.hpp>
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
                             std::to_string(now.time_of_day().total_microseconds()).substr(0,5);
    return now_string;
}

bool fileExists(std::string fileName){
    std::ifstream file(fileName);
    if(!file.good()) return false;
    file.close();
    return true;
}

int monthFromStr(std::string str){
    std::string months[13];
    months[1]="Jan";
    months[2]="Feb";
    months[3]="Mar";
    months[4]="Apr";
    months[5]="May";
    months[6]="Jun";
    months[7]="Jul";
    months[8]="Aug";
    months[9]="Sep";
    months[10]="Oct";
    months[11]="Nov";
    months[12]="Dec";
    int month;
    for(int i=1;i<=12;i++){
        if(str==months[i])
        {
            month=i;
        }
    }
    return month;
}

std::string arrayConstCharToString(const unsigned char* text){
    std::string str;
    for(int i=0;i<strlen(reinterpret_cast<const char *>(text)); i++){
        str+=text[i];
    }
    return str;
}