#include <string>
#include <memory>
#include "model/Bank.h"
#include "model/Interest.h"
#include "managers/ClientManager.h"
#include "managers/AccountManager.h"
#include "managers/TransactionManager.h"



Bank::Bank(){
    interest = std::make_shared<Interest>(0.01,0.19);
    clientManager = std::make_shared<ClientManager>();
    accountManager = std::make_shared<AccountManager>();
    transactionManager = std::make_shared<TransactionManager>();
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


