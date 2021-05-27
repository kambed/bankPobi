#include <string>
#include "model/Bank.h"
#include "model/Interest.h"
//#include "ClientManager.h"
//#include "AccountManager.h"
//#include "TransactionManager.h"



Bank::Bank(const std::string &bankNumber) : bankNumber(bankNumber) {}

const std::string &Bank::getBankNumber() const {
    return bankNumber;
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


