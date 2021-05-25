//
// Created by student on 25.05.2021.
//

#ifndef BANK_ACCOUNTMANAGER_H
#define BANK_ACCOUNTMANAGER_H

#include "repositories/AccountRepository.h"

class AccountManager {
private:
    AccountRepository accountRepository;
public:
    //CONSTRUCTOR
    AccountManager();
    //METHODS
    AccountPtr getAccount(std::string accountNumber);
    void createCurrentAccount(ClientPtr owner);
    void createSavingsAccount(ClientPtr owner,std::string currentAccountNumber);
    bool removeAccount(std::string accountNumber);
    bool setBalance(std::string accountNumber,double balance);
    std::vector<AccountPtr> findAll();
    std::vector<AccountPtr> findAccounts(AccountPredicate predicate);
};


#endif //BANK_ACCOUNTMANAGER_H
