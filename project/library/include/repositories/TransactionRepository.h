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
    ///CONTRUCTOR
    TransactionRepository();
    ///METHODS

    TransactionPtr getTransaction(boost::uuids::uuid Id);

    void addTransaction(TransactionPtr transaction);

    std::vector<TransactionPtr> findBy(TransactionPredicate predicate);
};


#endif //BANK_TRANSACTIONREPOSITORY_H
