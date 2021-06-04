#ifndef BANK_TRANSACTIONEXECEPTION_H
#define BANK_TRANSACTIONEXECEPTION_H


#include <stdexcept>

class TransactionExeception  : public std::logic_error{
public:
    TransactionExeception(const std::string &arg);
};


#endif //BANK_TRANSACTIONEXECEPTION_H
