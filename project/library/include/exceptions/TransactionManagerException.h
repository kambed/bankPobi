#ifndef BANK_TRANSACTIONMANAGEREXCEPTION_H
#define BANK_TRANSACTIONMANAGEREXCEPTION_H


#include <stdexcept>

class TransactionManagerException : public std::logic_error {
public:
    /// \param arg
    TransactionManagerException(const std::string &arg);
};


#endif //BANK_TRANSACTIONMANAGEREXCEPTION_H
