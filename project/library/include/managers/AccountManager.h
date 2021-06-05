//
// Created by student on 25.05.2021.
//

#ifndef BANK_ACCOUNTMANAGER_H
#define BANK_ACCOUNTMANAGER_H

#include "repositories/AccountRepository.h"
#include <memory>
class AccountManager : public std::enable_shared_from_this<AccountManager>{
private:
    AccountRepositoryPtr accountRepository;
    TransactionManagerPtr transactionManager;
    TurboLoggerPtr turboLogger;
    TurboSaverPtr turboSaver;
    InterestPtr interest;
public:
    //CONSTRUCTOR
    AccountManager(const TurboLoggerPtr &turboLogger, const TurboSaverPtr &turboSaver,TransactionManagerPtr transactionManager, InterestPtr interest);

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
