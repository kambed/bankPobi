//
// Created by student on 27.05.2021.
//

#ifndef BANK_TRANSACTIONREPOSITORY_H
#define BANK_TRANSACTIONREPOSITORY_H

#include <vector>
#include <boost/uuid/uuid.hpp>
#include "typedefs.h"

class TransactionRepository {
private:
    std::vector<TransactionPtr> transactions;
public:
    /// CONTRUCTOR

    TransactionRepository();

    /// METHODS

    /// \param Id
    /// \return TransactionPtr
    TransactionPtr getTransaction(boost::uuids::uuid Id);

    /// \param transaction
    void addTransaction(TransactionPtr transaction);

    /// \param predicate
    /// \return std::vector<TransactionPtr>
    std::vector<TransactionPtr> findBy(TransactionPredicate predicate);
};


#endif //BANK_TRANSACTIONREPOSITORY_H
