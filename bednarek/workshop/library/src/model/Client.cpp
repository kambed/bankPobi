//
// Created by student on 20.03.2021.
//

#include <iostream>
#include <string>
#include "model/Address.h"
#include "model/Client.h"
#include "typedefs.h"

//CONSTRUCTOR
Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
               const AddressPtr &address, const ClientTypePtr &clientType) : firstName(firstName), lastName(lastName),
                                                                             personalID(personalId), address(address),
                                                                             clientType(clientType) {}
//DESTRUCTOR
Client::~Client() {}

//GETTERS
const std::string Client::getClientInfo() const{
    return "Client:" + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo() + " " + clientType->getTypeInfo();
}
const std::string &Client::getFirstName() const {
    return firstName;
}
const std::string &Client::getLastName() const {
    return lastName;
}
const std::string &Client::getPersonalId() const {
    return personalID;
}
const AddressPtr Client::getAddress() const {
    return address;
}

//SETTERS
void Client::setFirstName(const std::string &firstName) {
    if(firstName!="")
    {
        Client::firstName = firstName;
    }
}
void Client::setLastName(const std::string &lastName) {
    if(lastName!="")
    {
        Client::lastName = lastName;
    }
}
void Client::setAddress(AddressPtr address) {
    if(address!=nullptr)
    {
        Client::address = address;
    }
}
void Client::setClientType(const ClientTypePtr &clientType) {
    Client::clientType = clientType;
}
int Client::getMaxVehicles() {
    return clientType->getMaxVehicles();
}
double Client::applyDiscount(double price) {
    return clientType->applyDiscount(price);
}
