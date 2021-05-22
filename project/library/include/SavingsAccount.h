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
public:
    //CONSTRUCTOR
    SavingsAccount(const ClientPtr &owner);
    //DESTRUCTOR
    virtual ~SavingsAccount();
    //GETTERS
    bool getWasInterestThisMonth() const;
    const boost::posix_time::ptime &getLastInterest() const;
    //METHODS
    std::string getAccountInfo() const override;
    bool sendToCurrentAccount(double amount);
    double chargeInterest();
};


#endif //BANK_SAVINGSACCOUNT_H
