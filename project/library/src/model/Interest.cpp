#include "model/Interest.h"

Interest::Interest(double percentage, double tax) : percentage(percentage), tax(tax) {}

double Interest::getPercentage() const {
    return percentage;
}

void Interest::setPercentage(double percentage) {
    if(percentage>=0)
        Interest::percentage = percentage;
}

double Interest::getTax() const {
    return tax;
}

void Interest::setTax(double tax) {
    if(tax>=0 && tax<=1)
        Interest::tax = tax;
}

int getNumberOfDaysInYear(int year){
    if( (year%4==0 && year%100!=0) || year%400==0)  //Rok jest przestepny jesli jest podzielny przez 4 i niepodzielny
        return 366;                                 // przez 100 lub podzielny przez 400
    else return 365;
}

double Interest::calculate(double balance,boost::posix_time::ptime lastInterestCharge) {
    boost::posix_time::time_period period(lastInterestCharge,boost::posix_time::second_clock::local_time());
    return balance*((period.length().hours() / 24 + 1)/getNumberOfDaysInYear(lastInterestCharge.date().year()))*percentage*
    (1-tax);
    //Oprocentowanie liczymy dzielac
    // ilosc dni od ostatniego rozliczenia przez ilosc dni w roku (wyliczmy fragment roku, w koncu oprocentowanie
    // jest w skali roku)
}
