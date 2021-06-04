#ifndef BANK_INTERESTEXCEPTION_H
#define BANK_INTERESTEXCEPTION_H


#include <stdexcept>

class InterestException  : public std::logic_error{
public:
    InterestException(const std::string &arg);
};


#endif //BANK_INTERESTEXCEPTION_H
