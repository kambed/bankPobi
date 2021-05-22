//
// Created by student on 22.05.2021.
//

#include "Account.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

Account::Account(const ClientPtr &owner) : owner(owner) {}

Account::~Account() {

}

const std::string &Account::getAccountNumber() const {
    return accountNumber;
}

const ClientPtr &Account::getOwner() const {
    return owner;
}

double Account::getBalance() const {
    return balance;
}

const boost::posix_time::ptime &Account::getCreationDate() const {
    return creationDate;
}

std::string Account::getAccountInfo() const {
    std::stringstream ss;
    ss << creationDate;
    std::string creation = ss.str();
    return "Numer konta: "+accountNumber+" Wlasciciel: "+" Stan konta: "+std::to_string(getBalance())+"zl Data zalozenia: "+creation;
    //+getOwner()->getClientInfo()
}

bool Account::sendMoney(std::string accountNumber, double amount) {
    return false; //TO BE IMPLEMENTED
}
