//
// Created by student on 22.05.2021.
//

#include "model/CurrentAccount.h"
#include "model/TurboSaver.h"

CurrentAccount::CurrentAccount(const ClientPtr &owner,int ClientAccNumber,TurboSaverPtr turboSaver,double balance,
                               boost::posix_time::ptime creationDate) : Account(owner,ClientAccNumber,turboSaver,balance,creationDate){}

CurrentAccount::~CurrentAccount() {}

std::string CurrentAccount::getAccountInfo() const {
    return "KONTO ROZLICZENIOWE "+Account::getAccountInfo();
}

bool CurrentAccount::setBalance(double balance) {
    if(Account::setBalance(balance)){
        turboSaver->saveCurrentAccount(shared_from_this());
    }
    return Account::setBalance(balance);
}
