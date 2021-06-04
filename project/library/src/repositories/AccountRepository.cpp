//
// Created by student on 25.05.2021.
//

#include "repositories/AccountRepository.h"
#include "model/Account.h"

AccountRepository::AccountRepository() {}

AccountPtr AccountRepository::getAccount(std::string accountNumber) {
    for (int i = 0; i<accounts.size(); i++) {
        if (accounts[i]->getAccountNumber() == accountNumber)
            return accounts[i];
    }
    return nullptr;
}

void AccountRepository::addAccount(AccountPtr account) {
    if (account != nullptr)
        accounts.push_back(account);
}

bool AccountRepository::removeAccount(AccountPtr account) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i] == account){
            accounts.erase(std::remove(accounts.begin(),accounts.end(),account));
            return true;
        }
    }
    return false;
}

std::vector<AccountPtr> AccountRepository::findBy(AccountPredicate predicate) {
    std::vector<AccountPtr> found;
    for (int i = 0; i < accounts.size(); i++) {
        AccountPtr account = accounts[i];
        if (account != nullptr && predicate(account)) {
            found.push_back(account);
        }
    }
    return found;
}

bool AccountRepository::setBalance(AccountPtr account, double balance) {
    account->setBalance(balance);
    return true;
}
