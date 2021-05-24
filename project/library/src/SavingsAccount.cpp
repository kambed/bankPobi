//
// Created by student on 22.05.2021.
//

#include "SavingsAccount.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>

SavingsAccount::SavingsAccount(const ClientPtr &owner, const AccountPtr &currentAccount) : Account(owner),
                                                                                           currentAccount(currentAccount), wasTransferThisMonth(false), lastInterest(getCreationDate()){}

SavingsAccount::~SavingsAccount() {

}

bool SavingsAccount::getWasTransferThisMonth() const {
    return wasTransferThisMonth;
}

const boost::posix_time::ptime &SavingsAccount::getLastInterest() const {
    return lastInterest;
}
const AccountPtr &SavingsAccount::getCurrentAccount() const {
    return currentAccount;
}
std::string SavingsAccount::getAccountInfo() const {
    std::stringstream ss;
    ss << lastInterest;
    std::string interest = ss.str();
    return "KONTO OSZCZEDNOSCIOWE " + Account::getAccountInfo() + " Transfer w tym miesiacu: " + std::to_string(
            getWasTransferThisMonth()) + " Ostatnie naliczenie odsetek: " + interest;
}

bool SavingsAccount::sendToCurrentAccount(double amount) {
    return false; //TO BE IMPLEMENTED
}

double SavingsAccount::chargeInterest() {
    return 0; //TO BE IMPLEMENTED
}
