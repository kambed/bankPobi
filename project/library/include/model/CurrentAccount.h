//
// Created by student on 22.05.2021.
//

#ifndef BANK_CURRENTACCOUNT_H
#define BANK_CURRENTACCOUNT_H

#include <boost/functional/hash.hpp>
#include "Account.h"

class CurrentAccount : public Account{
private:

public:
    //CONSTRUCTOR
    CurrentAccount(const ClientPtr &owner,int ClientAccNumber,TransactionManagerPtr transactionManager,AccountManagerPtr accountManager);
    //DESTRUCTOR
    virtual ~CurrentAccount();
    //METHODS
    std::string getAccountInfo() const override;
    bool sendToSavingsAccount(double amount);
    bool sendMoney(std::string accountNumber, double amount, std::string title) override;
};


#endif //BANK_CURRENTACCOUNT_H
