//
// Created by student on 22.05.2021.
//

#include "model/CurrentAccount.h"
#include "model/TurboSaver.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

CurrentAccount::CurrentAccount(const ClientPtr &owner, int clientAccountNumber, double balance,
                               const boost::posix_time::ptime &creationDate,const InterestPtr &interest)
                               : Account(owner,clientAccountNumber,balance,creationDate,
                                         creationDate,nullptr,interest) {}

CurrentAccount::~CurrentAccount() {}

std::string CurrentAccount::getAccountInfo() const {
    return "KONTO ROZLICZENIOWE "+Account::getAccountInfo();
}

void CurrentAccount::chargeInterest() {
    getConnectedAccount()->chargeInterest();
}
