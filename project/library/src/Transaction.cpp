#include "Transaction.h"
#include <boost/uuid/uuid_io.hpp>
#include "Account.h"


Transaction::Transaction(const AccountPtr &accountFrom, const AccountPtr &accountTo, double amount,
                         const std::string &title) : accountFrom(accountFrom), accountTo(accountTo), amount(amount),
                                                     title(title) {}

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
    return boost::uuids::to_string(id)+": z "+accountFrom->getAccountNumber()+" do "+accountTo->getAccountNumber()+
                                                                                                    ",tytul: "+title;
}


