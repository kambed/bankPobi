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
    /// CONSTRUCTOR
    /// \param firstName
    /// \param lastName
    /// \param personalID
    /// \param adres
    /// \param clientType
    Client(const std::string &firstName, const std::string &lastName, const std::string &personalID, AddressPtr adres,
           ClientTypePtr clientType);

    /// DESTRUCTOR

    ~Client();

    /// GETTERS

    /// \return
    const std::string getInfo() const;

    /// \return
    const std::string getClientInfo() const;

    /// \return
    const std::string &getFirstName() const;

    /// \return
    const std::string &getLastName() const;

    /// \return
    const std::string &getId() const;

    /// \return
    const std::string &getPersonalId() const;

    /// \return
    const AddressPtr getAddress() const;

    /// \return
    const int getMaxVehicles() const;

    /// SETTERS

    /// \param firstName
    void setFirstName(const std::string &firstName);

    /// \param lastName
    void setLastName(const std::string &lastName);

    /// \param address
    void setAddress(AddressPtr address);

    /// \param clientType
    void setClientType(std::shared_ptr<ClientType> clientType);

    /// \param archive
    void setArchive(bool archive);

    /// METHODS

    /// \param price
    /// \return
    const double applyDiscount(double price) const;

    /// \return
    bool isArchive() const;
};


#endif //CARRENTAL_CLIENT_H
