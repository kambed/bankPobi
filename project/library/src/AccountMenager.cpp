//
// Created by student on 25.05.2021.
//

#include "AccountMenager.h"
#include "Client.h"
#include "Account.h"
#include "CurrentAccount.h"
#include "SavingsAccount.h"

AccountMenager::AccountMenager(const AccountRepository &accountRepository) : accountRepository(accountRepository) {}

AccountPtr AccountMenager::getAccount(std::string accountNumber) {
    return accountRepository.getAccount(accountNumber);
}

void AccountMenager::createCurrentAccount(ClientPtr owner) {
    CurrentAccountPtr account = std::make_shared<CurrentAccount>(owner,owner->getPersonalId());
    accountRepository.addAccount(account);
}

void AccountMenager::createSavingsAccount(ClientPtr owner, std::string currentAccountNumber) {
    SavingsAccountPtr account = std::make_shared<SavingsAccount>(owner,accountRepository.getAccount(currentAccountNumber));
    accountRepository.addAccount(account);
}

bool AccountMenager::removeAccount(std::string accountNumber) {
    return accountRepository.removeAccount(accountRepository.getAccount(accountNumber));
}

bool AccountMenager::setBalance(std::string accountNumber, double balance) {
    accountRepository.getAccount(accountNumber)->setBalance(balance);
    return true;
}

std::vector<AccountPtr> AccountMenager::findAll() {
    auto function = [&](const AccountPtr &ptr)->bool{return(true);};
    return accountRepository.findBy(function);
}

std::vector<AccountPtr> AccountMenager::findAccounts(AccountPredicate predicate) {
    auto function = [&](const AccountPtr &ptr)->bool{return(predicate(ptr));};
    return accountRepository.findBy(function);
}


