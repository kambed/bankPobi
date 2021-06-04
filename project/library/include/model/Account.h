//
// Created by student on 22.05.2021.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


#include <string>
#include <boost/date_time/posix_time/ptime.hpp>
#include "./typedefs.h"

class Account {
private:
    std::string accountNumber;
    ClientPtr owner;
    double balance;
    boost::posix_time::ptime creationDate;
public:
    //CONSTRUCTOR
    Account(const ClientPtr &owner,int clientAccNumber);
    //DESTRUCTOR
    virtual ~Account()=0;
    //GETTERS
    const std::string &getAccountNumber() const;
    const ClientPtr &getOwner() const;
    double getBalance() const;
    const boost::posix_time::ptime &getCreationDate() const;
    //SETTERS
    void setBalance(double balance);
    //METHODS
    virtual std::string getAccountInfo() const;
    virtual bool sendMoney(std::string accountNumber,double amount,std::string title,TransactionManagerPtr transactionManager,AccountManagerPtr accountManager);
};


#endif //BANK_ACCOUNT_H
