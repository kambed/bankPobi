#ifndef BANK_INTEREST_H
#define BANK_INTEREST_H

#include <boost/date_time.hpp>

class Interest {
private:
    double percentage;
    double tax;
public:
    ///CONSTRUCTOR

    /// \param percentage
    /// \param tax
    Interest(double percentage, double tax);

    ///GETTERS

    /// \return double
    double getPercentage() const;

    /// \return double
    double getTax() const;

    ///SETTERS

    /// \param percentage
    void setPercentage(double percentage);

    /// \param tax
    void setTax(double tax);

    /// METHODS

    /// \param balance
    /// \param lastInterestCharge
    /// \return double
    double calculate(double balance,boost::posix_time::ptime lastInterestCharge);
};


#endif //BANK_INTEREST_H
