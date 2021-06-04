#ifndef BANK_INTEREST_H
#define BANK_INTEREST_H

#include <boost/date_time.hpp>

class Interest {
private:
    double percentage;
    double tax;
public:
    ///CONSTRUCTOR
    Interest(double percentage, double tax);
    ///GETTERS
    double getPercentage() const;
    double getTax() const;
    ///SETTERS
    void setPercentage(double percentage);
    void setTax(double tax);
    ///METHODS
    double calculate(double balance,boost::posix_time::ptime lastInterestCharge);
};


#endif //BANK_INTEREST_H
