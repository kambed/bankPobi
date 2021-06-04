#ifndef BANK_TURBOLOGGEREXCEPTION_H
#define BANK_TURBOLOGGEREXCEPTION_H


#include <stdexcept>

class TurboLoggerException : public std::logic_error{
public:
    TurboLoggerException(const std::string &arg);
};


#endif //BANK_TURBOLOGGEREXCEPTION_H
