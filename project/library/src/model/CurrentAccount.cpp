//
// Created by student on 22.05.2021.
//

#include "model/CurrentAccount.h"
#include "model/TurboSaver.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

CurrentAccount::CurrentAccount(const ClientPtr &owner,int ClientAccNumber,double balance,
                               boost::posix_time::ptime creationDate) : Account(owner,ClientAccNumber,balance,creationDate){}

CurrentAccount::~CurrentAccount() {}

std::string CurrentAccount::getAccountInfo() const {
    return "KONTO ROZLICZENIOWE "+Account::getAccountInfo();
}

bool CurrentAccount::setBalance(double balance) {
    return Account::setBalance(balance);
}

const boost::posix_time::ptime &CurrentAccount::getLastInterest() const {
    return getCreationDate();
}
const AccountPtr &CurrentAccount::getCurrentAccount() const {
    return NULL;
}
void CurrentAccount::chargeInterest() {}
