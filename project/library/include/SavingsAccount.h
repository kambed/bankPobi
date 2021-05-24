//
// Created by student on 22.05.2021.
//

#ifndef BANK_SAVINGSACCOUNT_H
#define BANK_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account{
private:
    bool wasTransferThisMonth;
    boost::posix_time::ptime lastInterest;
    AccountPtr currentAccount;
public:
    //CONSTRUCTOR
    SavingsAccount(const ClientPtr &owner, const AccountPtr &currentAccount);
    //DESTRUCTOR
    virtual ~SavingsAccount();
    //GETTERS
    bool getWasTransferThisMonth() const;
    const boost::posix_time::ptime &getLastInterest() const;
    const AccountPtr &getCurrentAccount() const;
    //METHODS
    std::string getAccountInfo() const override;
    bool sendToCurrentAccount(double amount);
    double chargeInterest();
};


#endif //BANK_SAVINGSACCOUNT_H
