//
// Created by student on 22.05.2021.
//

#include "CurrentAccount.h"

CurrentAccount::CurrentAccount(const ClientPtr &owner, const std::string &password) : Account(owner),
                                                                                      password(password) {}

CurrentAccount::~CurrentAccount() {

}

std::string CurrentAccount::getAccountInfo() const {
    return "KONTO ROZLICZENIOWE "+Account::getAccountInfo();
}

bool CurrentAccount::changePassword(std::string passwd) {
    password=passwd;
    return true;
}

bool CurrentAccount::sendToSavingsAccount(double amount) {
    return false;
}

bool CurrentAccount::sendMoney(std::string account, double amount, std::string password) {
    return false;
}
