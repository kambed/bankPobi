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
    sqlite3 *dbc,*dbt,*dbca,*dbsa;
    std::string sql;
    char* error;

public:
    TurboSaver();
    void saveClient(ClientPtr client);
    void saveSavingsAccount(SavingsAccountPtr account);
    void saveCurrentAccount(CurrentAccountPtr account);
    void removeAccount(std::string accnum);
    void saveTransaction(TransactionPtr transaction);

    void importClients(ClientManagerPtr clientManager);

    int countClients();
    int countCurrentAccounts();
    int countSavingsAccounts();
    int countTransactions();
};


#endif //BANK_TURBOSAVER_H
