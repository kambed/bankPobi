#ifndef BANK_ACCOUNTMANAGEREXCEPTION_H
#define BANK_ACCOUNTMANAGEREXCEPTION_H


#include <stdexcept>

class AccountManagerException : public std::logic_error {
public:
    AccountManagerException(const std::string &arg);
};


#endif //BANK_ACCOUNTMANAGEREXCEPTION_H
