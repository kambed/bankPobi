#include <boost/date_time/posix_time/ptime.hpp>

/// \param dateTime
/// \return string
std::string dateTimeToString(boost::posix_time::ptime dateTime);

/// \return string
std::string nowString();

/// \return string
std::string nowFileName();

/// \param str
/// \return int
int monthFromStr(std::string str);

/// \param text
/// \return sting
std::string arrayConstCharToString(const unsigned char* text);

/// \param fileName
/// \return bool
bool fileExists(std::string fileName);
