#include <string>
#include <memory>
#include "model/Bank.h"
#include "model/Interest.h"
#include "managers/ClientManager.h"
#include "managers/AccountManager.h"
#include "managers/TransactionManager.h"
#include "model/TurboLogger.h"
#include "model/TurboSaver.h"

Bank::Bank(){
    turboSaver = std::make_shared<TurboSaver>();
    turboLogger = std::make_shared<TurboLogger>();
    interest = std::make_shared<Interest>(0.01,0.19);
    clientManager = std::make_shared<ClientManager>(turboLogger,turboSaver);
    transactionManager = std::make_shared<TransactionManager>(turboLogger,turboSaver);
    accountManager = std::make_shared<AccountManager>(turboLogger,turboSaver,transactionManager,interest);
    turboSaver->importClients(clientManager);
    turboSaver->importCurrentAccounts(accountManager,clientManager);
    turboSaver->importSavingsAccounts(accountManager,clientManager);
    turboSaver->importTransactions(transactionManager,accountManager);
}

const InterestPtr &Bank::getInterest() const {
    return interest;
}

const ClientManagerPtr &Bank::getClientManager() const {
    return clientManager;
}

const AccountManagerPtr &Bank::getAccountManager() const {
    return accountManager;
}

const TransactionManagerPtr &Bank::getTransactionManager() const {
    return transactionManager;
}

const TurboSaverPtr &Bank::getTurboSaver() const {
    return turboSaver;
}


