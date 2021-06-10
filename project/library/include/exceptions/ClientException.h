#ifndef BANK_CLIENTEXCEPTION_H
#define BANK_CLIENTEXCEPTION_H


#include <stdexcept>

class ClientException : public std::logic_error{
public:
    /// \param arg
    ClientException(const std::string &arg);
};


#endif //BANK_CLIENTEXCEPTION_H
