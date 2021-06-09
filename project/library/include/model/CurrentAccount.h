//
// Created by student on 22.05.2021.
//

#ifndef BANK_CURRENTACCOUNT_H
#define BANK_CURRENTACCOUNT_H

#include <boost/date_time/posix_time/ptime.hpp>
#include "Account.h"

class CurrentAccount : public Account{
public:
    ///CONSTRUCTOR
    CurrentAccount(const ClientPtr &owner,int ClientAccNumber,double balance,boost::posix_time::ptime creationDate);
    ///DESTRUCTOR
    virtual ~CurrentAccount();
    ///METHODS
    std::string getAccountInfo() const override;
    ///SETTERS
    bool setBalance(double balance) override;

    virtual const boost::posix_time::ptime &getLastInterest() const override;
    virtual const AccountPtr &getCurrentAccount() const override;
    virtual void chargeInterest() override;
};


#endif //BANK_CURRENTACCOUNT_H
