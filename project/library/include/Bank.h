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
    std::string bankNumber;
	InterestPtr interest;
//	ClientManagerPtr clientManager;
//	AccountManagerPtr accountManager;
//	TransactionManagerPtr transactionManager;

public:
    Bank(const std::string &bankNumber);

    const std::string &getBankNumber() const;

    const InterestPtr &getInterest() const;

//    const ClientManagerPtr &getClientManager() const;
//
//    const AccountManagerPtr &getAccountManager() const;
//
//    const TransactionManagerPtr &getTransactionManager() const;


};

#endif
