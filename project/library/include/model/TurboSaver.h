//
// Created by student on 04.06.2021.
//

#ifndef BANK_TURBOSAVER_H
#define BANK_TURBOSAVER_H

#include <typedefs.h>
#include <sqlite3.h>

class TurboSaver {
private:
    sqlite3 *db;
    std::string sqlQuery;
    char* error;
    bool open;
public:
    ///CONSTRUCTOR
    TurboSaver();
    ///METHODS

    /// \param client
    void saveClient(ClientPtr client);

    /// \param account
    void saveSavingsAccount(AccountPtr account);

    /// \param account
    void saveCurrentAccount(AccountPtr account);

    /// \param accountNumber
    void removeAccount(std::string accountNumber);

    /// \param transaction
    void saveTransaction(TransactionPtr transaction);

    /// \param clientManager
    void importClients(ClientManagerPtr clientManager);

    /// \param accountManager
    /// \param clientManager
    void importSavingsAccounts(AccountManagerPtr accountManager,ClientManagerPtr clientManager);

    /// \param accountManager
    /// \param clientManager
    void importCurrentAccounts(AccountManagerPtr accountManager,ClientManagerPtr clientManager);

    /// \param transactionManager
    /// \param accountManager
    void importTransactions(TransactionManagerPtr transactionManager,AccountManagerPtr accountManager);

    /// \return int
    int countClients();

    /// \return int
    int countCurrentAccounts();

    /// \return int
    int countSavingsAccounts();

    /// \return int
    int countTransactions();
};


#endif //BANK_TURBOSAVER_H
