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
    TurboSaverPtr turboSaver;
public:
    ///CONSTRUCTOR

    /// \param turboLogger
    /// \param turboSaver
    TransactionManager(const TurboLoggerPtr &turboLogger,const TurboSaverPtr &turboSaver);

    ///METHODS

    /// \param id
    /// \param accountFrom
    /// \param accountTo
    /// \param amount
    /// \param title
    void createTransaction(std::string id,AccountPtr accountFrom,AccountPtr accountTo,double amount,std::string title);

    /// \param id
    /// \param accountFrom
    /// \param accountTo
    /// \param amount
    /// \param title
    void saveTransaction(std::string id,AccountPtr accountFrom,AccountPtr accountTo,double amount,std::string title);

    /// \param Id
    /// \return TransactionPtr
    TransactionPtr getTransaction(std::string Id);

    /// \return std::vector<TransactionPtr>
    std::vector<TransactionPtr> findAll();

    /// \param predicate
    /// \return std::vector<TransactionPtr>
    std::vector<TransactionPtr> findTransactions(TransactionManagerPtr predicate);
};


#endif //BANK_TRANSACTIONMANAGER_H
