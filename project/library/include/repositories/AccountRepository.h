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
    ///CONTRUCTOR
    AccountRepository();
    ///METHODS
    AccountPtr getAccount(std::string accountNumber);
    void addAccount(AccountPtr account);
    bool removeAccount(AccountPtr account);
    bool setBalance(AccountPtr account,double balance);
    std::vector<AccountPtr> findBy(AccountPredicate predicate);
};


#endif //BANK_ACCOUNTREPOSITORY_H
