#ifndef BANK_TRANSACTION_H
#define BANK_TRANSACTION_H

#include <boost/uuid/uuid.hpp>
#include "typedefs.h"

class Transaction {
private:
    boost::uuids::uuid id;
    AccountPtr accountFrom;
    AccountPtr accountTo;
    double amount;
    std::string title;
public:
    ///CONSTRUCTOR
    Transaction(const AccountPtr &accountFrom, const AccountPtr &accountTo, double amount,
                const std::string &title);
    ///GETTERS
    const boost::uuids::uuid &getId() const;

    const AccountPtr &getAccountFrom() const;

    const AccountPtr &getAccountTo() const;

    double getAmount() const;

    const std::string &getTitle() const;
    ///METHODS
    // bool transferMoney(std::string accountFrom,std::string accountTo,double amount);
    std::string getTransactionInfo();
};


#endif //BANK_TRANSACTION_H
