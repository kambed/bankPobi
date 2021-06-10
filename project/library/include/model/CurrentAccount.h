//
// Created by student on 22.05.2021.
//

#ifndef BANK_CURRENTACCOUNT_H
#define BANK_CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account{
public:
    ///CONSTRUCTOR
    CurrentAccount(const ClientPtr &owner, int clientAccNumber, double balance,
                   const boost::posix_time::ptime &creationDate,
                   const InterestPtr &interest);
    ///DESTRUCTOR
    virtual ~CurrentAccount();
    ///METHODS
    std::string getAccountInfo() const override;
    void chargeInterest() override;
    ///SETTERS
    bool setBalance(double balance) override;
};


#endif //BANK_CURRENTACCOUNT_H
