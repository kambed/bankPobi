//
// Created by student on 25.05.2021.
//

#ifndef BANK_ACCOUNTMENAGER_H
#define BANK_ACCOUNTMENAGER_H

#include "AccountRepository.h"

class AccountMenager {
private:
    AccountRepository accountRepository;
public:
    //CONSTRUCTOR
    AccountMenager(const AccountRepository &accountRepository);
    //METHODS
    AccountPtr getAccount(std::string accountNumber);
    void createCurrentAccount(ClientPtr owner);
    void createSavingsAccount(ClientPtr owner,std::string currentAccountNumber);
    bool removeAccount(std::string accountNumber);
    bool setBalance(std::string accountNumber,double balance);
    std::vector<AccountPtr> findAll();
    std::vector<AccountPtr> findAccounts(AccountPredicate predicate);
};


#endif //BANK_ACCOUNTMENAGER_H
