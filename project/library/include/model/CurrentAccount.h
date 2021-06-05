//
// Created by student on 22.05.2021.
//

#ifndef BANK_CURRENTACCOUNT_H
#define BANK_CURRENTACCOUNT_H

#include <boost/functional/hash.hpp>
#include "Account.h"

class CurrentAccount : public Account,public std::enable_shared_from_this<CurrentAccount>{
public:
    //CONSTRUCTOR
    CurrentAccount(const ClientPtr &owner,int ClientAccNumber,TransactionManagerPtr transactionManager,AccountManagerPtr accountManager,TurboSaverPtr turboSaver);
    //DESTRUCTOR
    virtual ~CurrentAccount();
    //METHODS
    std::string getAccountInfo() const override;
    bool sendMoney(std::string accountNumber, double amount, std::string title) override;

    bool setBalance(double balance) override;
};


#endif //BANK_CURRENTACCOUNT_H
