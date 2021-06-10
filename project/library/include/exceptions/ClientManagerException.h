#ifndef BANK_CLIENTMANAGEREXCEPTION_H
#define BANK_CLIENTMANAGEREXCEPTION_H


#include <stdexcept>

class ClientManagerException : public std::logic_error{
public:
    /// \param arg
    ClientManagerException(const std::string &arg);
};


#endif //BANK_CLIENTMANAGEREXCEPTION_H
