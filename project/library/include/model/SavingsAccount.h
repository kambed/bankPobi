//
// Created by student on 22.05.2021.
//

#ifndef BANK_SAVINGSACCOUNT_H
#define BANK_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account,public std::enable_shared_from_this<SavingsAccount>{
private:
    boost::posix_time::ptime lastInterest;
    AccountPtr currentAccount;
    InterestPtr interest;
public:
    //CONSTRUCTOR
    SavingsAccount(const ClientPtr &owner, int clientAccNumber,const AccountPtr &currentAccount, const InterestPtr
    &interest, TurboSaverPtr turboSaver,double balance,boost::posix_time::ptime creationDate,boost::posix_time::ptime
    lastInterest);
    //DESTRUCTOR
    virtual ~SavingsAccount();
    //GETTERS
    const boost::posix_time::ptime &getLastInterest() const;
    const AccountPtr &getCurrentAccount() const;
    //METHODS
    std::string getAccountInfo() const override;
    void chargeInterest();
    bool setBalance(double balance) override;
};


#endif //BANK_SAVINGSACCOUNT_H
