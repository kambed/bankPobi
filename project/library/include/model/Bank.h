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
    ///CONSTRUCTOR
    Bank();
    ///GETTERS

    /// \return InterestPtr
    const InterestPtr &getInterest() const;

    /// \return ClientManagerPtr
    const ClientManagerPtr &getClientManager() const;

    /// \return AccountManagerPtr
    const AccountManagerPtr &getAccountManager() const;

    /// \return TransactionManagerPtr
    const TransactionManagerPtr &getTransactionManager() const;

    /// \return TurboSaverPtr
    const TurboSaverPtr &getTurboSaver() const;


};

#endif
