//
// Created by student on 20.03.2021.
//

#include <iostream>
#include <string>
#include "model/Client.h"
#include "model/Address.h"
using namespace std;

Client::Client(const string &firstName, const string &lastName, const string &personalId, Address *address) : firstName(firstName), lastName(lastName), personalID(personalId), address(address) {}

Client::~Client() {}

string Client::getClientInfo() {
    return "Client:" + firstName + " " + lastName + " " + personalID + " " + address->getAddressInfo();
}

const string &Client::getFirstName() const {
    return firstName;
}

const string &Client::getLastName() const {
    return lastName;
}

const string &Client::getPersonalId() const {
    return personalID;
}

void Client::setFirstName(const string &firstName) {
    if(firstName!="")
    {
        Client::firstName = firstName;
    }
}

void Client::setLastName(const string &lastName) {
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

