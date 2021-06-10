//
// Created by student on 25.05.2021.
//

#ifndef BANK_ACCOUNTMANAGER_H
#define BANK_ACCOUNTMANAGER_H

#include "typedefs.h"
#include <vector>
#include <boost/date_time/posix_time/ptime.hpp>

class AccountManager : public std::enable_shared_from_this<AccountManager>{
private:
    AccountRepositoryPtr accountRepository;
    TurboLoggerPtr turboLogger;
    TurboSaverPtr turboSaver;
    InterestPtr interest;
public:
    /// CONSTRUCTOR

    /// \param turboLogger
    /// \param turboSaver
    /// \param interest
    AccountManager(const TurboLoggerPtr &turboLogger, const TurboSaverPtr &turboSaver,InterestPtr interest);

    ///METHODS

    /// \param accountNumber
    /// \return AccountPtr
    AccountPtr getAccount(std::string accountNumber);

    /// \param owner
    /// \param savingsAccountNumber
    /// \param balance
    /// \param creationDate
    void createCurrentAccount(ClientPtr owner, std::string savingsAccountNumber, double balance, boost::posix_time::ptime creationDate);

    /// \param owner
    /// \param currentAccountNumber
    /// \param balance
    /// \param creationDate
    /// \param lastInterest
    void createSavingsAccount(ClientPtr owner, std::string currentAccountNumber, double balance, boost::posix_time::ptime creationDate,
                              boost::posix_time::ptime lastInterest);

    /// \param accountNumber
    /// \return bool
    bool removeAccount(std::string accountNumber);

    /// \param accountNumber
    /// \param balance
    /// \return bool
    bool setBalance(std::string accountNumber,double balance);

    /// \return std::vector<AccountPtr>
    std::vector<AccountPtr> findAll();

    /// \param predicate
    /// \return std::vector<AccountPtr>
    std::vector<AccountPtr> findAccounts(AccountPredicate predicate);
};


#endif //BANK_ACCOUNTMANAGER_H
