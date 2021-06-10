//
// Created by student on 25.05.2021.
//

#ifndef BANK_ACCOUNTREPOSITORY_H
#define BANK_ACCOUNTREPOSITORY_H

#include <vector>
#include "typedefs.h"

class AccountRepository {
private:
    std::vector<AccountPtr> accounts;
public:
    /// CONTRUCTOR

    AccountRepository();

    ///METHODS

    /// \param accountNumber
    /// \return AccountPtr
    AccountPtr getAccount(std::string accountNumber);

    /// \param account
    void addAccount(AccountPtr account);

    /// \param account
    /// \return bool
    bool removeAccount(AccountPtr account);

    /// \param account
    /// \param balance
    /// \return bool
    bool setBalance(AccountPtr account,double balance);

    /// \param predicate
    /// \return std::vector<AccountPtr>
    std::vector<AccountPtr> findBy(AccountPredicate predicate);
};


#endif //BANK_ACCOUNTREPOSITORY_H
