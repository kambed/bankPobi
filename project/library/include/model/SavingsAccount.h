//
// Created by student on 22.05.2021.
//

#ifndef BANK_SAVINGSACCOUNT_H
#define BANK_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account{
public:
    ///CONSTRUCTOR

    /// \param owner
    /// \param clientAccNumber
    /// \param balance
    /// \param creationDate
    /// \param lastInterest
    /// \param connectedAccount
    /// \param interest
    SavingsAccount(const ClientPtr &owner, int clientAccountNumber, double balance,
                   const boost::posix_time::ptime &creationDate, const boost::posix_time::ptime &lastInterest,
                   const AccountPtr &connectedAccount, const InterestPtr &interest);
    ///DESTRUCTOR
    virtual ~SavingsAccount();

    ///METHODS

    /// \return string
    std::string getAccountInfo() const override;

    void chargeInterest() override;
};


#endif //BANK_SAVINGSACCOUNT_H
