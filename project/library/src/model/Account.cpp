//
// Created by student on 22.05.2021.
//

#include "model/Account.h"
#include "model/Client.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <cstdlib>
#include <ctime>

Account::Account(const ClientPtr &owner) : owner(owner),balance(0),creationDate(boost::posix_time::second_clock::local_time()) {
    srand(time(NULL));
    int kontrol;
    kontrol=rand()%90+10;
    accountNumber=std::to_string(kontrol)+"246813570"+getOwner()->getPersonalId()+"TO BE DONE(NUMER KONTA KLIENTA)";
}

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
    return "Numer konta: "+accountNumber+" Wlasciciel: "+getOwner()->getClientInfo()+" Stan konta: "+std::to_string(getBalance())+"zl Data zalozenia: "+creation;

}

bool Account::sendMoney(std::string accountNumber, double amount) {
    return false; //TO BE IMPLEMENTED
}

void Account::setBalance(double balance) {
    if(balance >= 0)
        Account::balance = balance;
}
