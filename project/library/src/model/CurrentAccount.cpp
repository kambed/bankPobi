//
// Created by student on 22.05.2021.
//

#include "model/CurrentAccount.h"
#include "model/TurboSaver.h"

CurrentAccount::CurrentAccount(const ClientPtr &owner,int ClientAccNumber,TransactionManagerPtr transactionManager,AccountManagerPtr accountManager,TurboSaverPtr turboSaver) : Account(owner,ClientAccNumber,transactionManager,accountManager,turboSaver){}

CurrentAccount::~CurrentAccount() {

}

std::string CurrentAccount::getAccountInfo() const {
    return "KONTO ROZLICZENIOWE "+Account::getAccountInfo();
}

bool CurrentAccount::sendMoney(std::string accountNumber, double amount, std::string title) {
    return Account::sendMoney(accountNumber, amount, title);
}

bool CurrentAccount::setBalance(double balance) {
    if(Account::setBalance(balance)){
        turboSaver->saveCurrentAccount(shared_from_this());
    }
    return Account::setBalance(balance);
}
