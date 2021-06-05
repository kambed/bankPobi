//
// Created by student on 25.05.2021.
//

#include "managers/AccountManager.h"
#include "model/Client.h"
#include "model/Account.h"
#include "model/Interest.h"
#include "repositories/AccountRepository.h"
#include "model/CurrentAccount.h"
#include "model/SavingsAccount.h"
#include "model/TurboLogger.h"
#include "model/TurboSaver.h"

AccountManager::AccountManager(const TurboLoggerPtr &turboLogger,const TurboSaverPtr &turboSaver,TransactionManagerPtr transactionManager,
                               InterestPtr interest) : turboLogger(turboLogger),turboSaver(turboSaver),transactionManager
                               (transactionManager), interest(interest) {
    accountRepository = std::make_shared<AccountRepository>();
}

AccountPtr AccountManager::getAccount(std::string accountNumber) {
    return accountRepository->getAccount(accountNumber);
}

void AccountManager::createCurrentAccount(ClientPtr owner) {
    auto function = [&](const AccountPtr &ptr)->bool{return(ptr->getOwner()==owner);};
    int number=findAccounts(function).size();
    if(number<=8999) {
        CurrentAccountPtr account = std::make_shared<CurrentAccount>(owner,number,transactionManager,shared_from_this());
        accountRepository->addAccount(account);
        turboLogger->addLog("Create: "+account->getAccountInfo());
        turboSaver->saveCurrentAccount(account);
    }else{
        turboLogger->addLog("Create account fail: wlasiciel: "+owner->getClientInfo());
    }
}

void AccountManager::createSavingsAccount(ClientPtr owner, std::string currentAccountNumber) {
    auto function = [&](const AccountPtr &ptr)->bool{return(ptr->getOwner()==owner);};
    int number=findAccounts(function).size();
    if(number<=8999){
        SavingsAccountPtr account2 = std::make_shared<SavingsAccount>(owner,number,transactionManager,
                                                                      shared_from_this(),
                                                                      accountRepository->getAccount(currentAccountNumber),interest);
        accountRepository->addAccount(account2);
        turboLogger->addLog("Create: "+account2->getAccountInfo());
        turboSaver->saveSavingsAccount(account2);
    }else{
        turboLogger->addLog("Create account fail: wlasiciel: "+owner->getClientInfo()+
        "; konto bierzacae"+accountRepository->getAccount(currentAccountNumber)->getAccountInfo());
    }
}

bool AccountManager::removeAccount(std::string accountNumber) {
    bool status = accountRepository->removeAccount(accountRepository->getAccount(accountNumber));
    if(status==true)
    {
        turboLogger->addLog("Remove: "+accountNumber);
        turboSaver->removeAccount(accountNumber);
    }
    else turboLogger->addLog("Remove failed: "+accountNumber);
    return status;
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