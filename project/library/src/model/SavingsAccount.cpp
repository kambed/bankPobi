//
// Created by student on 22.05.2021.
//

#include "model/SavingsAccount.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <exceptions/AccountException.h>
#include "functions.h"
#include "model/Interest.h"
#include "model/TurboSaver.h"

SavingsAccount::SavingsAccount(const ClientPtr &owner, int clientAccNumber, double balance,
                               const boost::posix_time::ptime &creationDate,
                               const boost::posix_time::ptime &lastInterest, const AccountPtr &connectedacc,
                               const InterestPtr &interest) : Account(owner, clientAccNumber, balance, creationDate,
                                                                      lastInterest, connectedacc, interest) {
    if(connectedacc == nullptr) throw AccountException("Empty connected account");
}

SavingsAccount::~SavingsAccount() {}

std::string SavingsAccount::getAccountInfo() const {
    return "KONTO OSZCZEDNOSCIOWE " + Account::getAccountInfo() + " Ostatnie naliczenie odsetek: " + dateTimeToString(getLastInterest());
}

void SavingsAccount::chargeInterest() {
    setBalance(getBalance()+interest->calculate(getBalance(),getLastInterest()));
}

bool SavingsAccount::setBalance(double balance) {
    return Account::setBalance(balance);
}
