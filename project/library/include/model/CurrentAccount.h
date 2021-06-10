//
// Created by student on 22.05.2021.
//

#ifndef BANK_CURRENTACCOUNT_H
#define BANK_CURRENTACCOUNT_H

#include "Account.h"

class CurrentAccount : public Account{
public:
    ///CONSTRUCTOR

    /// \param owner
    /// \param clientAccountNumber
    /// \param balance
    /// \param creationDate
    /// \param interest
    CurrentAccount(const ClientPtr &owner, int clientAccountNumber, double balance,
                   const boost::posix_time::ptime &creationDate,
                   const InterestPtr &interest);
    ///DESTRUCTOR
    virtual ~CurrentAccount();
    ///METHODS

    /// \return string
    std::string getAccountInfo() const override;

    void chargeInterest() override;
};


#endif //BANK_CURRENTACCOUNT_H
