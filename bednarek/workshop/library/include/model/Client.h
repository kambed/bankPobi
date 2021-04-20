//
// Created by student on 20.03.2021.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include "Address.h"
#include "Rent.h"
#include "../typedefs.h"
#include <vector>

class Rent;
class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    std::vector<RentPtr> currentRents;
public:
    //CONSTRUCTOR
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId, AddressPtr address);
    //DESTRUCTOR
    virtual ~Client();

    //GETTERS
    const std::string getClientInfo() const;
    const std::string getFullClientInfo() const;
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalId() const;
    const Address *getAddress() const;
    const std::vector<Rent *> &getCurrentRents() const;

    //SETTERS
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setAddress(AddressPtr address);

    //METHODS
    void setCurrentRents(RentPtr rent);
    void removeCurrentRent(RentPtr rent);
};


#endif //CARRENTAL_CLIENT_H
