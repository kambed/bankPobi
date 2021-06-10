#ifndef BANK_ACCOUNTMANAGEREXCEPTION_H
#define BANK_ACCOUNTMANAGEREXCEPTION_H


#include <stdexcept>

class AccountManagerException : public std::logic_error {
public:

    /// \param arg
    AccountManagerException(const std::string &arg);
};


#endif //BANK_ACCOUNTMANAGEREXCEPTION_H
