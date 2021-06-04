//
// Created by student on 22.05.2021.
//

#include "model/CurrentAccount.h"

CurrentAccount::CurrentAccount(const ClientPtr &owner,int ClientAccNumber,TransactionManagerPtr transactionManager,AccountManagerPtr accountManager) : Account(owner,ClientAccNumber,transactionManager,accountManager){}

CurrentAccount::~CurrentAccount() {

}

std::string CurrentAccount::getAccountInfo() const {
    return "KONTO ROZLICZENIOWE "+Account::getAccountInfo();
}

bool CurrentAccount::sendToSavingsAccount(double amount) {
    return false;
}

bool CurrentAccount::sendMoney(std::string accountNumber, double amount, std::string title) {
    return Account::sendMoney(accountNumber, amount, title);
}
