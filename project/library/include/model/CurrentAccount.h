//
// Created by student on 22.05.2021.
//

#ifndef BANK_CURRENTACCOUNT_H
#define BANK_CURRENTACCOUNT_H

#include <boost/functional/hash.hpp>
#include "Account.h"

class CurrentAccount : public Account{
private:
    std::string password;
public:
    //CONSTRUCTOR
    CurrentAccount(const ClientPtr &owner, const std::string &password);
    //DESTRUCTOR
    virtual ~CurrentAccount();
    //METHODS
    std::string getAccountInfo() const override;
    bool changePassword(std::string passwd);
    bool sendToSavingsAccount(double amount);
    bool sendMoney(std::string account,double amount,std::string password);


};


#endif //BANK_CURRENTACCOUNT_H
