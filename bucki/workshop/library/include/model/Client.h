#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include "Address.h"
#include "Rent.h"
#include <vector>

class Rent;
class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    Client();
public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID,AddressPtr adres);

    ~Client();

    const std::string getClientInfo() const;

    const std::string &getFirstName() const;
    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;
    void setLastName(const std::string &lastName);

    const std::string &getPersonalId() const;

    const AddressPtr getAddress() const;
    void setAddress(AddressPtr address);
};


#endif //CARRENTAL_CLIENT_H
