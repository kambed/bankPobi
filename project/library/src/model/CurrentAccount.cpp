//
// Created by student on 22.05.2021.
//

#include "model/CurrentAccount.h"
#include <boost/date_time/posix_time/ptime.hpp>

CurrentAccount::CurrentAccount(const ClientPtr &owner, int clientAccNumber, double balance,
                               const boost::posix_time::ptime &creationDate,
                               const InterestPtr &interest) : Account(owner, clientAccNumber, balance, creationDate,
                                                                      creationDate, nullptr, interest) {}

CurrentAccount::~CurrentAccount() {}

std::string CurrentAccount::getAccountInfo() const {
    return "KONTO ROZLICZENIOWE "+Account::getAccountInfo();
}

bool CurrentAccount::setBalance(double balance) {
    return Account::setBalance(balance);
}

void CurrentAccount::chargeInterest() {
    getConnectedAccount()->chargeInterest();
}
