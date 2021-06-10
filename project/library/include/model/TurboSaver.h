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
    sqlite3 *db;
    std::string sqlQuery;
    char* error;
    bool open;
public:
    TurboSaver();

    void saveClient(ClientPtr client);
    void saveSavingsAccount(AccountPtr account);
    void saveCurrentAccount(AccountPtr account);
    void removeAccount(std::string accountNumber);
    void saveTransaction(TransactionPtr transaction);

    void importClients(ClientManagerPtr clientManager);
    void importSavingsAccounts(AccountManagerPtr accountManager,ClientManagerPtr clientManager);
    void importCurrentAccounts(AccountManagerPtr accountManager,ClientManagerPtr clientManager);
    void importTransactions(TransactionManagerPtr transactionManager,AccountManagerPtr accountManager);

    int countClients();
    int countCurrentAccounts();
    int countSavingsAccounts();
    int countTransactions();
};


#endif //BANK_TURBOSAVER_H
