//
// Created by student on 27.05.2021.
//

#include "repositories/TransactionRepository.h"
#include "model/Transaction.h"
#include "templates.h"

TransactionRepository::TransactionRepository() {}

TransactionPtr TransactionRepository::getTransaction(boost::uuids::uuid Id) {
    for (int i = 0; i < transactions.size(); i++) {
        TransactionPtr transaction = transactions[i];
        if (transaction->getId() == Id)
            return transaction;
    }
    return nullptr;
}

void TransactionRepository::addTransaction(TransactionPtr transaction) {
    if (transaction != nullptr){
        transactions.push_back(transaction);
    }
}

std::vector<TransactionPtr> TransactionRepository::findBy(TransactionPredicate predicate) {
    return findByTemplate<TransactionPtr,TransactionPredicate>(predicate,transactions);
}
