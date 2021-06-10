//
// Created by student on 27.05.2021.
//

#include "exceptions/TransactionException.h"
#include "managers/TransactionManager.h"
#include "repositories/TransactionRepository.h"
#include "model/Transaction.h"
#include "model/Account.h"
#include "exceptions/TransactionManagerException.h"
#include "model/TurboLogger.h"
#include "model/TurboSaver.h"

TransactionManager::TransactionManager(const TurboLoggerPtr &turboLogger,const TurboSaverPtr &turboSaver) : turboLogger(turboLogger),turboSaver(turboSaver) {
    transactionRepository = std::make_shared<TransactionRepository>();
    if(turboLogger == nullptr) throw TransactionManagerException("Empty TurboLogger");
    if(turboSaver == nullptr) throw TransactionManagerException("Empty TurboSaver");
}

TransactionPtr TransactionManager::getTransaction(boost::uuids::uuid Id) {
    return transactionRepository->getTransaction(Id);
}

std::vector<TransactionPtr> TransactionManager::findAll() {
    auto function = [&](const TransactionPtr &ptr)->bool{return(true);};
    return transactionRepository->findBy(function);
}

std::vector<TransactionPtr> TransactionManager::findTransactions(TransactionManagerPtr predicate) {
    return findTransactions(predicate);
}

void TransactionManager::createTransaction(std::string id,AccountPtr accountFrom, AccountPtr accountTo, double amount, std::string
title) {
    if(amount > accountFrom->getBalance()){
        throw TransactionException("Too low balance of account "+accountFrom->getAccountNumber()+" to send "
                                   +std::to_string(amount));
    }else if(accountTo == nullptr){
        throw TransactionException("Too low balance of account form");
    }else{
        saveTransaction(id,accountFrom,accountTo,amount,title);
        accountFrom->setBalance(accountFrom->getBalance()-amount);
        accountTo->setBalance(accountTo->getBalance()+amount);
    }
}

void TransactionManager::saveTransaction(std::string id, AccountPtr accountFrom, AccountPtr accountTo, double amount,
                                           std::string title) {
        TransactionPtr trans = std::make_shared<Transaction>("",accountFrom,accountTo,amount,title);
        transactionRepository->addTransaction(trans);
        turboLogger->addLog("Transaction: "+trans->getTransactionInfo());
}
