//
// Created by student on 22.05.2021.
//

#include "SavingsAccount.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

SavingsAccount::SavingsAccount(const ClientPtr &owner) : Account(owner) {}

SavingsAccount::~SavingsAccount() {

}

bool SavingsAccount::getWasInterestThisMonth() const {
    return wasTransferThisMonth;
}

const boost::posix_time::ptime &SavingsAccount::getLastInterest() const {
    return lastInterest;
}

std::string SavingsAccount::getAccountInfo() const {
    std::stringstream ss;
    ss << lastInterest;
    std::string interest = ss.str();
    return "KONTO OSZCZEDNOSCIOWE "+Account::getAccountInfo()+" Transfer w tym miesiacu: "+std::to_string(getWasInterestThisMonth())+" Ostatnie naliczenie odsetek: "+interest;
}

bool SavingsAccount::sendToCurrentAccount(double amount) {
    return false; //TO BE IMPLEMENTED
}

double SavingsAccount::chargeInterest() {
    return 0; //TO BE IMPLEMENTED
}
