#ifndef CARRENTAL_CLIENT_H
#define CARRENTAL_CLIENT_H

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
    Client();
public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID,AddressPtr adres,
           ClientTypePtr clientType);

    ~Client();

    const std::string getClientInfo() const;

    const std::string &getFirstName() const;
    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;
    void setLastName(const std::string &lastName);

    const std::string &getPersonalId() const;

    const AddressPtr getAddress() const;
    void setAddress(AddressPtr address);

    void setClientType(std::shared_ptr<ClientType> clientType);

    const int getMaxVehicles() const;

    const double applyDiscount(double price) const;

};


#endif //CARRENTAL_CLIENT_H
