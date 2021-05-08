#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

#include "typedefs.h"
#include "model/Address.h"
#include "model/Rent.h"
#include "ClientType.h"
#include <vector>

class Rent;

class Client {
private:
    std::string firstName;
    std::string lastName;
    std::string personalID;
    AddressPtr address;
    ClientTypePtr clientType;
    bool archive = false;
    Client();

public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr adres,
           ClientTypePtr clientType);

    ~Client();

    const std::string getInfo() const;

    const std::string getClientInfo() const;

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    const std::string &getId() const;

    const std::string &getPersonalId() const;

    const AddressPtr getAddress() const;

    void setAddress(AddressPtr address);

    void setClientType(std::shared_ptr<ClientType> clientType);

    const int getMaxVehicles() const;

    const double applyDiscount(double price) const;

    bool isArchive() const;

    void setArchive(bool archive);
};


#endif //CARRENTAL_CLIENT_H
