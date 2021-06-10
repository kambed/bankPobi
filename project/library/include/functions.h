#include <boost/date_time/posix_time/ptime.hpp>
std::string dateTimeToString(boost::posix_time::ptime dateTime);

std::string nowString();

std::string nowFileName();

int monthFromStr(std::string str);

std::string arrayConstCharToString(const unsigned char* text);

bool fileExists(std::string fileName);
