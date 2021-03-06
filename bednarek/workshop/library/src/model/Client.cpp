//
// Created by student on 20.03.2021.
//

#include <iostream>
#include <string>
#include "model/Address.h"
#include "model/Client.h"
#include "typedefs.h"
#include "exceptions/ClientException.h"

//CONSTRUCTOR
Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
               const AddressPtr &address, const ClientTypePtr &clientType) try : firstName(firstName), lastName(lastName),
                                                                             personalID(personalId), address(address),
                                                                             clientType(clientType) {
    if(firstName.empty()) throw ClientException("FirstName Empty");
    if(lastName.empty()) throw ClientException("LastName Empty");
    if(personalId.empty()) throw ClientException("personalID Empty");
    if(address== nullptr) throw ClientException("Address Empty");
    if(clientType== nullptr) throw ClientException("ClientType Empty");
}
                                                                             catch(const ClientException &exception){
                                                                                 std::cout<<"Exception: "<<exception.what()<<std::endl;
                                                                             }
//DESTRUCTOR
Client::~Client() {}

//GETTERS
const std::string Client::getInfo() const {
    return getClientInfo();
}
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
const std::string &Client::getId() const {
    return getPersonalId();
}
const AddressPtr Client::getAddress() const {
    return address;
}
bool Client::isArchive() const {
    return archive;
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
void Client::setArchive(bool archive) {
    Client::archive = archive;
}

int Client::getMaxVehicles() {
    return clientType->getMaxVehicles();
}
double Client::applyDiscount(double price) {
    return clientType->applyDiscount(price);
}
