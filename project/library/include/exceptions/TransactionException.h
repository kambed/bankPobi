#ifndef BANK_TRANSACTIONEXCEPTION_H
#define BANK_TRANSACTIONEXCEPTION_H


#include <stdexcept>

class TransactionException  : public std::logic_error{
public:
    TransactionException(const std::string &arg);
};


#endif //BANK_TRANSACTIONEXCEPTION_H
