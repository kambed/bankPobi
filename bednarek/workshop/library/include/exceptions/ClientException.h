//
// Created by student on 03.05.2021.
//

#ifndef CARRENTAL_CLIENTEXCEPTION_H
#define CARRENTAL_CLIENTEXCEPTION_H

#include <stdexcept>

class ClientException : public std::logic_error {
public:
    ClientException(const std::string &arg);
};


#endif //CARRENTAL_CLIENTEXCEPTION_H
