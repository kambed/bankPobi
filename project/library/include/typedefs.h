#ifndef BANK_TYPEDEFS_H
#define BANK_TYPEDEFS_H

#include <memory>
#include <functional>

class Client;
class Account;
class SavingsAccount;
class CurrentAccount;
class Transaction;

class Interest;

class ClientRepository;
class TransactionRepository;
class AccountRepository;

class ClientManager;
class AccountManager;
class TransactionManager;

class Bank;
class TurboLogger;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<Account> AccountPtr;
typedef std::shared_ptr<SavingsAccount> SavingsAccountPtr;
typedef std::shared_ptr<CurrentAccount> CurrentAccountPtr;
typedef std::shared_ptr<Transaction> TransactionPtr;

typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(AccountPtr)> AccountPredicate;
typedef std::function<bool(TransactionPtr)> TransactionPredicate;

typedef std::shared_ptr<TransactionRepository> TransactionRepositoryPtr;
typedef std::shared_ptr<AccountRepository> AccountRepositoryPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;

typedef std::shared_ptr<Interest> InterestPtr;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<AccountManager> AccountManagerPtr;
typedef std::shared_ptr<TransactionManager> TransactionManagerPtr;

typedef std::shared_ptr<Bank> BankPtr;
typedef std::shared_ptr<TurboLogger> TurboLoggerPtr;

#endif //BANK_TYPEDEFS_H
