#ifndef BANK_ACCOUNTEXCEPTION_H
#define BANK_ACCOUNTEXCEPTION_H


#include <stdexcept>

class AccountException : public std::logic_error{
public:
    /// \param arg
    AccountException(const std::string &arg);
};


#endif //BANK_ACCOUNTEXCEPTION_H
