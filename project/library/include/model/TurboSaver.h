//
// Created by student on 04.06.2021.
//

#ifndef BANK_TURBOSAVER_H
#define BANK_TURBOSAVER_H

#include <typedefs.h>
#include <string>
#include <sqlite3.h>
#include "model/TurboLogger.h"

class TurboSaver {
private:
    ClientManagerPtr clientManager;
    TransactionManagerPtr transactionManager;
    AccountManagerPtr accountManager;
    sqlite3 *dbc,*dbt,*dbca,*dbsa;
    std::string sql;
    char* error;

public:
    TurboSaver(const ClientManagerPtr &clientManager, const TransactionManagerPtr &transactionManager,
               const AccountManagerPtr &accountManager);
    void saveClient(ClientPtr client);
    void importClient();
    //void saveAccount(AccountPtr account);
    //void saveTransaction(TransactionPtr transaction);
};


#endif //BANK_TURBOSAVER_H
