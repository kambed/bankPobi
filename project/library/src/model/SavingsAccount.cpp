//
// Created by student on 22.05.2021.
//

#include "model/SavingsAccount.h"
#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time.hpp>
#include <exceptions/AccountException.h>
#include "functions.h"

SavingsAccount::SavingsAccount(const ClientPtr &owner, const AccountPtr &currentAccount,int ClientAccNumber) try : Account(owner,ClientAccNumber),
                                                                                           currentAccount(currentAccount), wasTransferThisMonth(false), lastInterest(getCreationDate()){
    if(currentAccount == nullptr) throw AccountException("Empty currentAccount");
}catch(const AccountException &exception){
    std::cout << "Exception: " << exception.what() << std::endl;
}

SavingsAccount::~SavingsAccount() {}

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
