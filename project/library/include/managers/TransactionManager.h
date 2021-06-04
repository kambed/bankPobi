//
// Created by student on 27.05.2021.
//

#ifndef BANK_TRANSACTIONMANAGER_H
#define BANK_TRANSACTIONMANAGER_H

#include <boost/uuid/uuid.hpp>
#include <typedefs.h>
#include <vector>

class TransactionManager {
private:
    TransactionRepositoryPtr transactionRepository;
    TurboLoggerPtr turboLogger;
public:
    ///CONSTRUCTOR
    TransactionManager(const TurboLoggerPtr &turboLogger);

    ///METHODS
    void createTransaction(AccountPtr accountFrom,AccountPtr accountTo,double amount,std::string title);
    TransactionPtr getTransaction(boost::uuids::uuid Id);
    std::vector<TransactionPtr> findAll();
    std::vector<TransactionPtr> findTransactions(TransactionManagerPtr predicate);
};


#endif //BANK_TRANSACTIONMANAGER_H
