//
// Created by student on 22.05.2021.
//

#ifndef BANK_SAVINGSACCOUNT_H
#define BANK_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account,public std::enable_shared_from_this<SavingsAccount>{
private:
    bool wasTransferThisMonth;
    boost::posix_time::ptime lastInterest;
    AccountPtr currentAccount;
    InterestPtr interest;
public:
    //CONSTRUCTOR
    SavingsAccount(const ClientPtr &owner, int clientAccNumber, const TransactionManagerPtr &transactionManager,
                   const AccountManagerPtr &accountManager,const AccountPtr &currentAccount, const InterestPtr
                   &interest,TurboSaverPtr turboSaver);
    //DESTRUCTOR
    virtual ~SavingsAccount();
    //GETTERS
    bool getWasTransferThisMonth() const;
    const boost::posix_time::ptime &getLastInterest() const;
    const AccountPtr &getCurrentAccount() const;
    //METHODS
    std::string getAccountInfo() const override;
    bool sendToCurrentAccount(double amount);
    void chargeInterest();
    bool setBalance(double balance) override;
};


#endif //BANK_SAVINGSACCOUNT_H
