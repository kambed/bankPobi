//
// Created by student on 22.05.2021.
//

#include "model/SavingsAccount.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include "functions.h"

SavingsAccount::SavingsAccount(const ClientPtr &owner, const AccountPtr &currentAccount,int ClientAccNumber) : Account(owner,ClientAccNumber),
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
    return "KONTO OSZCZEDNOSCIOWE " + Account::getAccountInfo() + " Transfer w tym miesiacu: " + std::to_string(
            getWasTransferThisMonth()) + " Ostatnie naliczenie odsetek: " + dateTimeToString(lastInterest);
}

bool SavingsAccount::sendToCurrentAccount(double amount) {
    return false; //TO BE IMPLEMENTED
}

double SavingsAccount::chargeInterest() {
    return 0; //TO BE IMPLEMENTED
}
