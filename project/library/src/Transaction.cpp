#include "Transaction.h"
#include <boost/uuid/uuid_io.hpp>
#include "Account.h"
#include <boost/uuid/uuid_generators.hpp>

Transaction::Transaction(const AccountPtr &accountFrom, const AccountPtr &accountTo,
                         double amount, const std::string &title) : accountFrom(accountFrom),
                                                                    accountTo(accountTo), amount(amount),
                                                                    title(title) {
    boost::uuids::random_generator generator;
    id=generator();
}

const AccountPtr &Transaction::getAccountFrom() const {
    return accountFrom;
}

const AccountPtr &Transaction::getAccountTo() const {
    return accountTo;
}

double Transaction::getAmount() const {
    return amount;
}

const std::string &Transaction::getTitle() const {
    return title;
}

//bool Transaction::transferMoney(std::string accountFrom, std::string accountTo, double amount) {
//    return false;
//}

std::string Transaction::getTransactionInfo() {
    return boost::uuids::to_string(id)+": z "+accountFrom->getAccountNumber()+" do "+accountTo->getAccountNumber()+" Kwota: "+std::to_string(amount)+
                                                                                                    ",tytul: "+title;
}