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
    std::vector<Rent*> currentRents;
    Client();
public:
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID,Address *adres);

    ~Client();

    const std::string getClientInfo() const;

    const std::string getFullClientInfo() const;

    const std::string &getFirstName() const;
    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;
    void setLastName(const std::string &lastName);

    const std::string &getPersonalId() const;

    const Address *getAddress() const;
    void setAddress(Address *address);

    const std::vector<Rent *> &getCurrentRents() const;
    void addRent(Rent * rent);
    void removeRent(Rent * rent);
};


#endif //CARRENTAL_CLIENT_H
