//
// Created by student on 04.06.2021.
//

#ifndef BANK_TURBOSAVEREXCEPTION_H
#define BANK_TURBOSAVEREXCEPTION_H

#include <stdexcept>

class TurboSaverException : public std::logic_error {
public:
    TurboSaverException(const std::string &arg);
};


#endif //BANK_TURBOSAVEREXCEPTION_H
