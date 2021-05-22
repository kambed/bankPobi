#ifndef BANK_TYPEDEFS_H
#define BANK_TYPEDEFS_H

#include <memory>
#include <functional>

class Interest;
class ClientManager;
class AccountManager;
class TransactionManager;

typedef std::shared_ptr<Interest> InterestPtr;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<AccountManager> AccountManagerPtr;
typedef std::shared_ptr<TransactionManager> TransactionManagerPtr;

#endif //BANK_TYPEDEFS_H
