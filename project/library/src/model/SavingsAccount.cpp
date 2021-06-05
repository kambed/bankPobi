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


SavingsAccount::SavingsAccount(const ClientPtr &owner, int clientAccNumber,
                               const TransactionManagerPtr &transactionManager, const AccountManagerPtr &accountManager,
                                const AccountPtr &currentAccount, const InterestPtr &interest,TurboSaverPtr turboSaver)
                                try : Account(owner, clientAccNumber, transactionManager,
                               accountManager,turboSaver), wasTransferThisMonth(false), lastInterest(getCreationDate()),
                               currentAccount(currentAccount), interest(interest) {
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
    return Account::sendMoney(currentAccount->getAccountNumber(), amount, "Przelew z konta ROR");
}

void SavingsAccount::chargeInterest() {
    setBalance(getBalance()+interest->calculate(getBalance(),lastInterest));
}

bool SavingsAccount::setBalance(double balance) {
    if(Account::setBalance(balance)){
        turboSaver->saveSavingsAccount(shared_from_this());
    }
    return Account::setBalance(balance);
}

