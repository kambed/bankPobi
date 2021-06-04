#ifndef BANK_ACCOUNTEXCEPTION_H
#define BANK_ACCOUNTEXCEPTION_H


#include <stdexcept>

class AccountException : public std::logic_error{
public:
    AccountException(const std::string &arg);
};


#endif //BANK_ACCOUNTEXCEPTION_H
