//
// Created by student on 22.05.2021.
//

#include "model/CurrentAccount.h"

CurrentAccount::CurrentAccount(const ClientPtr &owner,int ClientAccNumber) : Account(owner,ClientAccNumber){}

CurrentAccount::~CurrentAccount() {

}

std::string CurrentAccount::getAccountInfo() const {
    return "KONTO ROZLICZENIOWE "+Account::getAccountInfo();
}

bool CurrentAccount::sendToSavingsAccount(double amount) {
    return false;
}

bool CurrentAccount::sendMoney(std::string accountNumber, double amount, std::string title,
                               TransactionManagerPtr transactionManager, AccountManagerPtr accountManager) {
    return Account::sendMoney(accountNumber, amount, title, transactionManager, accountManager);
}
