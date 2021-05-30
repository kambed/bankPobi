//
// Created by student on 25.05.2021.
//

#include "managers/AccountManager.h"
#include "model/Client.h"
#include "model/Account.h"
#include "repositories/AccountRepository.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"

AccountManager::AccountManager() {
    accountRepository = std::make_shared<AccountRepository>();
}

AccountPtr AccountManager::getAccount(std::string accountNumber) {
    return accountRepository->getAccount(accountNumber);
}

void AccountManager::createCurrentAccount(ClientPtr owner) {
    auto function = [&](const AccountPtr &ptr)->bool{return(ptr->getOwner()==owner);};
    int number=findAccounts(function).size();
    CurrentAccountPtr account = std::make_shared<CurrentAccount>(owner,number);
    accountRepository->addAccount(account);
}

void AccountManager::createSavingsAccount(ClientPtr owner, std::string currentAccountNumber) {
    auto function = [&](const AccountPtr &ptr)->bool{return(ptr->getOwner()==owner);};
    int number=findAccounts(function).size();
    SavingsAccountPtr account2 = std::make_shared<SavingsAccount>(owner,accountRepository->getAccount(currentAccountNumber),number);
    accountRepository->addAccount(account2);
}

bool AccountManager::removeAccount(std::string accountNumber) {
    return accountRepository->removeAccount(accountRepository->getAccount(accountNumber));
}

bool AccountManager::setBalance(std::string accountNumber, double balance) {
    accountRepository->getAccount(accountNumber)->setBalance(balance);
    return true;
}

std::vector<AccountPtr> AccountManager::findAll() {
    auto function = [&](const AccountPtr &ptr)->bool{return(true);};
    return accountRepository->findBy(function);
}

std::vector<AccountPtr> AccountManager::findAccounts(AccountPredicate predicate) {
    auto function = [&](const AccountPtr &ptr)->bool{return(predicate(ptr));};
    return accountRepository->findBy(function);
}


