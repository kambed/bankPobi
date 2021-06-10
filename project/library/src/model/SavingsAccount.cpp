//
// Created by student on 22.05.2021.
//

#include "model/SavingsAccount.h"
#include <exceptions/AccountException.h>
#include "functions.h"
#include "model/Interest.h"

SavingsAccount::SavingsAccount(const ClientPtr &owner, int clientAccountNumber, double balance,
                               const boost::posix_time::ptime &creationDate,
                               const boost::posix_time::ptime &lastInterest, const AccountPtr &connectedAccount,
                               const InterestPtr &interest) : Account(owner, clientAccountNumber, balance, creationDate,
                                                                      lastInterest, connectedAccount, interest) {
    if(connectedAccount == nullptr) throw AccountException("Empty connected account");
}

SavingsAccount::~SavingsAccount() {}

std::string SavingsAccount::getAccountInfo() const {
    return "KONTO OSZCZEDNOSCIOWE " + Account::getAccountInfo() + " Ostatnie naliczenie odsetek: " + dateTimeToString(getLastInterest());
}

void SavingsAccount::chargeInterest() {
    setBalance(getBalance()+interest->calculate(getBalance(),getLastInterest()));
}
