#include <string>

#ifndef BANK_H
#define BANK_H

#include <typedefs.h>

class Interest;
class ClientManager;
class AccountManager;
class TransactionManager;

class Bank
{
private:
	InterestPtr interest;
	ClientManagerPtr clientManager;
	AccountManagerPtr accountManager;
	TransactionManagerPtr transactionManager;
	TurboLoggerPtr turboLogger;
	TurboSaverPtr turboSaver;
public:
    Bank();

    const InterestPtr &getInterest() const;

    const ClientManagerPtr &getClientManager() const;

    const AccountManagerPtr &getAccountManager() const;

    const TransactionManagerPtr &getTransactionManager() const;


};

#endif
