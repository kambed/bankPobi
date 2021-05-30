#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <string>

std::string dateTimeToString(boost::posix_time::ptime dateTime);

std::string nowString();