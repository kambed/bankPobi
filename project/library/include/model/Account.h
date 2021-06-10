//
// Created by student on 22.05.2021.
//

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H


#include <string>
#include <boost/date_time/posix_time/ptime.hpp>
#include "./typedefs.h"

class Account{
private:
    std::string accountNumber;
    ClientPtr owner;
    double balance;
    boost::posix_time::ptime creationDate;
    boost::posix_time::ptime lastInterest;
    AccountPtr connectedAccount;
protected:
    InterestPtr interest;
public:
    /// CONSTRUCTOR

    /// \param owner
    /// \param clientAccountNumber
    /// \param balance
    /// \param creationDate
    /// \param lastInterest
    /// \param connectedAccount
    /// \param interest
    Account(const ClientPtr &owner, int clientAccountNumber, double balance, boost::posix_time::ptime creationDate,
            boost::posix_time::ptime lastInterest, AccountPtr connectedAccount, InterestPtr interest);

    /// DESTRUCTOR

    virtual ~Account()=0;

    /// GETTERS

    /// \return boost::posix_time::ptime
    const boost::posix_time::ptime &getLastInterest() const;

    /// \return AccountPtr
    const AccountPtr &getConnectedAccount() const;

    /// \return string
    const std::string &getAccountNumber() const;

    /// \return ClientPtr
    const ClientPtr &getOwner() const;

    /// \return duble
    double getBalance() const;

    /// \return boost::posix_time::ptime
    const boost::posix_time::ptime &getCreationDate() const;

    /// SETTERS


    /// \param balance
    /// \return bool
    bool setBalance(double balance);

    /// \param connectedAccount
    void setConnectedAccount(const AccountPtr &connectedAccount);

    /// METHODS

    /// \return string
    virtual std::string getAccountInfo() const;

    virtual void chargeInterest()=0;
};


#endif //BANK_ACCOUNT_H
