//
// Created by student on 22.05.2021.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


#include <string>
#include <boost/date_time/posix_time/ptime.hpp>
#include "./typedefs.h"

class Account{
private:
    std::string accountNumber;
    ClientPtr owner;
    double balance;
    boost::posix_time::ptime creationDate;

    boost::posix_time::ptime lastInterest;
    AccountPtr connectedAccount;
protected:
    InterestPtr interest;
public:
    //CONSTRUCTOR
    Account(const ClientPtr &owner,int clientAccNumber,double balance,boost::posix_time::ptime creationDate,boost::posix_time::ptime lastInterest,AccountPtr connectedacc,InterestPtr interest);
    //DESTRUCTOR
    virtual ~Account()=0;
    //GETTERS
    const boost::posix_time::ptime &getLastInterest() const;
    const AccountPtr &getConnectedAccount() const;
    const std::string &getAccountNumber() const;
    const ClientPtr &getOwner() const;
    double getBalance() const;
    const boost::posix_time::ptime &getCreationDate() const;
    //SETTERS
    virtual bool setBalance(double balance);
    void setConnectedAccount(const AccountPtr &connectedAccount);
    //METHODS
    virtual std::string getAccountInfo() const;
    virtual void chargeInterest()=0;
};


#endif //BANK_ACCOUNT_H
