//
// Created by student on 25.05.2021.
//

#include "managers/AccountManager.h"
#include "Client.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"

AccountManager::AccountManager() {}

AccountPtr AccountManager::getAccount(std::string accountNumber) {
    return accountRepository.getAccount(accountNumber);
}

void AccountManager::createCurrentAccount(ClientPtr owner) {
    CurrentAccountPtr account = std::make_shared<CurrentAccount>(owner,owner->getPersonalId());
    accountRepository.addAccount(account);
}

void AccountManager::createSavingsAccount(ClientPtr owner, std::string currentAccountNumber) {
    SavingsAccountPtr account2 = std::make_shared<SavingsAccount>(owner,accountRepository.getAccount(currentAccountNumber));
    accountRepository.addAccount(account2);
}

bool AccountManager::removeAccount(std::string accountNumber) {
    return accountRepository.removeAccount(accountRepository.getAccount(accountNumber));
}

bool AccountManager::setBalance(std::string accountNumber, double balance) {
    accountRepository.getAccount(accountNumber)->setBalance(balance);
    return true;
}

std::vector<AccountPtr> AccountManager::findAll() {
    auto function = [&](const AccountPtr &ptr)->bool{return(true);};
    return accountRepository.findBy(function);
}

std::vector<AccountPtr> AccountManager::findAccounts(AccountPredicate predicate) {
    auto function = [&](const AccountPtr &ptr)->bool{return(predicate(ptr));};
    return accountRepository.findBy(function);
}


