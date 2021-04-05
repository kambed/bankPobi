//
// Created by student on 20.03.2021.
//

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
    Address *address;
    std::vector<Rent *> currentRents;
public:

    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId, Address *address);

    virtual ~Client();

    std::string getClientInfo();

    std::string getFullClientInfo();

    const std::string &getFirstName() const;

    const std::string &getLastName() const;

    const std::string &getPersonalId() const;

    void setFirstName(const std::string &firstName);

    void setLastName(const std::string &lastName);

    const Address *getAddress() const;

    void setAddress(Address *address);

    std::string getCurrentRents();

    void setCurrentRents(Rent *rent);
};


#endif //CARRENTAL_CLIENT_H
