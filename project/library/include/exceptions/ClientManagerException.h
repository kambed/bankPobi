#ifndef BANK_CLIENTMANAGEREXCEPTION_H
#define BANK_CLIENTMANAGEREXCEPTION_H


#include <stdexcept>

class ClientManagerException : public std::logic_error{
public:
    ClientManagerException(const std::string &arg);
};


#endif //BANK_CLIENTMANAGEREXCEPTION_H
