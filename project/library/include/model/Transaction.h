#ifndef BANK_TRANSACTION_H
#define BANK_TRANSACTION_H

#include <boost/uuid/uuid.hpp>
#include "typedefs.h"

class Transaction {
private:
    boost::uuids::uuid id;
    AccountPtr accountFrom;
    AccountPtr accountTo;
    double amount;
    std::string title;
public:
    ///CONSTRUCTOR

    /// \param id
    /// \param accountFrom
    /// \param accountTo
    /// \param amount
    /// \param title
    Transaction(std::string id,const AccountPtr &accountFrom, const AccountPtr &accountTo, double amount,
                const std::string &title);
    ///GETTERS

    /// \return boost::uuids::uuid
    const boost::uuids::uuid &getId() const;

    /// \return AccountPtr
    const AccountPtr &getAccountFrom() const;

    /// \return AccountPtr
    const AccountPtr &getAccountTo() const;

    /// \return string
    double getAmount() const;

    /// \return string
    const std::string &getTitle() const;

    ///METHODS


    /// \return string
    std::string getTransactionInfo();
};


#endif //BANK_TRANSACTION_H
