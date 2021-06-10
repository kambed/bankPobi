//
// Created by student on 22.05.2021.
//

#include "model/Account.h"
#include "model/Client.h"
#include "model/TurboSaver.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <cstdlib>
#include <ctime>
#include <exceptions/AccountException.h>
#include "functions.h"
#include "managers/TransactionManager.h"
#include "managers/AccountManager.h"

Account::Account(const ClientPtr &owner,int clientAccNumber,double balance,
                 boost::posix_time::ptime creationDate2,boost::posix_time::ptime lastInterest2,AccountPtr connectedacc,
                 InterestPtr interest) : owner(owner),balance(balance),connectedAccount(connectedacc),interest(interest) {
    if(creationDate2==boost::posix_time::not_a_date_time){
        creationDate=boost::posix_time::second_clock::local_time();
    }
    else{
        creationDate=creationDate2;
    }
    if(lastInterest2==boost::posix_time::not_a_date_time) {
        lastInterest = creationDate;
    }
    else{
        lastInterest = lastInterest2;
    }
    if(owner == nullptr) throw AccountException("Empty owner");
    if(interest == nullptr) throw AccountException("Empty interest");
    if(clientAccNumber > 8999 || clientAccNumber < 0) throw AccountException("Bad clientAccNumber");
    if(balance<0) throw AccountException("Balance can't be less 0");
    int kontrol;
    kontrol= clientAccNumber % 100;
    if(kontrol<=9){
        kontrol=kontrol+10;
    }
    clientAccNumber= clientAccNumber + 1000;
    if(clientAccNumber <= 9999) {
        accountNumber=std::to_string(kontrol)+"246813570"+getOwner()->getPersonalId()+std::to_string(clientAccNumber);
    }
}

Account::~Account() {}

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

const boost::posix_time::ptime &Account::getLastInterest() const {
    return lastInterest;
}

const AccountPtr &Account::getConnectedAccount() const {
    return connectedAccount;
}

std::string Account::getAccountInfo() const {
    return "Numer konta: "+accountNumber+" Wlasciciel: "+getOwner()->getClientInfo()+" Stan konta: "+std::to_string
    (getBalance())+"zl Data zalozenia: "+dateTimeToString(creationDate);
}

bool Account::setBalance(double balance) {
    if(balance >= 0){
        Account::balance = balance;
        return true;
    }
    return false;
}

void Account::setConnectedAccount(const AccountPtr &connectedAccount2) {
    if(connectedAccount==nullptr)
        Account::connectedAccount = connectedAccount2;
}

