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
#include <typeinfo>

AccountManager::AccountManager(const TurboLoggerPtr &turboLogger,const TurboSaverPtr &turboSaver,InterestPtr interest)
                                : turboLogger(turboLogger),turboSaver(turboSaver),interest(interest) {
    accountRepository = std::make_shared<AccountRepository>();
}

AccountPtr AccountManager::getAccount(std::string accountNumber) {
    return accountRepository->getAccount(accountNumber);
}

void AccountManager::createCurrentAccount(ClientPtr owner,double balance,boost::posix_time::ptime creationDate) {
    auto function = [&](const AccountPtr &ptr)->bool{return(ptr->getOwner()==owner);};
    int number=findAccounts(function).size();
    if(number<=8999) {
        AccountPtr account = std::make_shared<CurrentAccount>(owner,number,balance,creationDate);
        accountRepository->addAccount(account);
        turboSaver->saveCurrentAccount(account);
        turboLogger->addLog("Create: "+account->getAccountInfo());

    }else{
        turboLogger->addLog("Create account fail: wlasiciel: "+owner->getClientInfo());
    }
}

void AccountManager::createSavingsAccount(ClientPtr owner, std::string currentAccountNumber,double balance,boost::posix_time::ptime creationDate,boost::posix_time::ptime lastInterest) {
    auto function = [&](const AccountPtr &ptr)->bool{return(ptr->getOwner()==owner);};
    int number=findAccounts(function).size();
    AccountPtr account2 = std::make_shared<SavingsAccount>(owner,number,accountRepository->getAccount(currentAccountNumber),
                                                                  interest,balance,creationDate,lastInterest);
    if(number<=8999){
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
    if(status==true){
        turboLogger->addLog("Remove: "+accountNumber);
        turboSaver->removeAccount(accountNumber);
    }
    else turboLogger->addLog("Remove failed: "+accountNumber);
    return status;
}

bool AccountManager::setBalance(std::string accountNumber, double balance) {
    if(typeid(accountRepository->getAccount(accountNumber)).name()=="CurrentAccount"){
        turboSaver->saveCurrentAccount(accountRepository->getAccount(accountNumber));
    }
    if(typeid(accountRepository->getAccount(accountNumber)).name()=="SavingsAccount"){
        turboSaver->saveSavingsAccount(accountRepository->getAccount(accountNumber));
    }
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