//
// Created by student on 22.05.2021.
//

#ifndef BANK_SAVINGSACCOUNT_H
#define BANK_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account{
public:
    //CONSTRUCTOR
    SavingsAccount(const ClientPtr &owner, int clientAccNumber, double balance,
                   const boost::posix_time::ptime &creationDate, const boost::posix_time::ptime &lastInterest,
                   const AccountPtr &connectedacc, const InterestPtr &interest);
    //DESTRUCTOR
    virtual ~SavingsAccount();
    //METHODS
    std::string getAccountInfo() const override;
    void chargeInterest() override;
    bool setBalance(double balance) override;
};


#endif //BANK_SAVINGSACCOUNT_H
