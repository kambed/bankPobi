//
// Created by student on 20.03.2021.
//

#include <iostream>
#include <string>
#include "model/Address.h"
#include "model/Client.h"

//CONSTRUCTOR
Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId,
               AddressPtr address) : firstName(firstName), lastName(lastName), personalID(personalId),
                                         address(address) {}
//DESTRUCTOR
Client::~Client() {}

//GETTERS
const std::string Client::getClientInfo() const{
    return "Client:" + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo();
}
const std::string Client::getFullClientInfo() const{
    std::string rentlist=" ";
    if(currentRents.size()==0)
    {
        return rentlist;
    }
    else
    {
        for(int i=0;i<currentRents.size();i++)
        {
            rentlist=rentlist + "\n" + currentRents[i]->getRentInfo();
        }
    }
    return "Client:" + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo() + " " + rentlist;
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
const Address *Client::getAddress() const {
    return address;
}
const std::vector<Rent *> &Client::getCurrentRents() const {
    return currentRents;
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

//METHODS
void Client::setCurrentRents(RentPtr rent) {
    currentRents.push_back(rent);
}
void Client::removeCurrentRent(RentPtr rent) {
    currentRents.erase(std::remove(currentRents.begin(),currentRents.end(),rent));
}


