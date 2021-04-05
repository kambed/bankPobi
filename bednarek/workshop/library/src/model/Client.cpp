//
// Created by student on 20.03.2021.
//

#include <iostream>
#include <string>
#include "model/Address.h"
#include "model/Client.h"

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalId, Address *address) : firstName(firstName), lastName(lastName), personalID(personalId), address(address) {}

Client::~Client() {}

std::string Client::getClientInfo() {
    return "Client:" + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo();
}

std::string Client::getFullClientInfo() {
    return "Client:" + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo() + " " + getCurrentRents();
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

const Address *Client::getAddress() const {
    return address;
}

void Client::setAddress(Address *address) {
    if(address!=nullptr)
    {
        Client::address = address;
    }
}

std::string Client::getCurrentRents() {
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
    return rentlist;
}

void Client::setCurrentRents(Rent *rent) {
    currentRents.push_back(rent);
}

