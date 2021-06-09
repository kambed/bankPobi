//
// Created by student on 25.05.2021.
//

#ifndef BANK_ACCOUNTMANAGER_H
#define BANK_ACCOUNTMANAGER_H

#include "repositories/AccountRepository.h"
#include <memory>
#include <boost/date_time/posix_time/ptime.hpp>

class AccountManager : public std::enable_shared_from_this<AccountManager>{
private:
    AccountRepositoryPtr accountRepository;
    TurboLoggerPtr turboLogger;
    TurboSaverPtr turboSaver;
    InterestPtr interest;
public:
    //CONSTRUCTOR
    AccountManager(const TurboLoggerPtr &turboLogger, const TurboSaverPtr &turboSaver,InterestPtr interest);

    //METHODS
    AccountPtr getAccount(std::string accountNumber);
    void createCurrentAccount(ClientPtr owner,std::string savingsAccountNumber,double balance,boost::posix_time::ptime creationDate);
    void createSavingsAccount(ClientPtr owner,std::string currentAccountNumber,double balance,boost::posix_time::ptime creationDate,
                              boost::posix_time::ptime lastInterest);
    bool removeAccount(std::string accountNumber);
    bool setBalance(std::string accountNumber,double balance);
    std::vector<AccountPtr> findAll();
    std::vector<AccountPtr> findAccounts(AccountPredicate predicate);
};


#endif //BANK_ACCOUNTMANAGER_H
