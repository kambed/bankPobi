//
// Created by student on 20.03.2021.
//

#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include "Address.h"
#include "Rent.h"
#include "../typedefs.h"
#include <vector>
#include "ClientType.h"

class Rent;
class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    ClientTypePtr clientType;
    bool archive=false;
public:
    //CONSTRUCTOR
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
           const AddressPtr &address, const ClientTypePtr &clientType);

    //DESTRUCTOR
    virtual ~Client();

    //GETTERS
    bool isArchive() const;
    const std::string getInfo() const;
    const std::string getClientInfo() const;
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const std::string &getPersonalId() const;
    const AddressPtr getAddress() const;

    //SETTERS
    void setArchive(bool archive);
    void setFirstName(const std::string &firstName);
    void setLastName(const std::string &lastName);
    void setAddress(AddressPtr address);
    void setClientType(const ClientTypePtr &clientType);

    //METHODS
    int getMaxVehicles();
    double applyDiscount(double price);

};


#endif //CARRENTAL_CLIENT_H
