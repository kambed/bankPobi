#include <algorithm>
#include <iostream>
#include <vector>
#include "model/Client.h"

using namespace std;

Client::Client() {
    //cout << "Utworzono klienta." << endl << endl;
}

Client::~Client() {
    //cout << "Usunieto klienta" << endl;
    //cout << getClientInfo() << endl << endl;
    //delete address;
}

const string Client::getClientInfo() const {
    return firstName + " " + lastName + " " + personalID + ", adres:" + address->getAddressInfo();
}

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID,
               AddressPtr address) : firstName (firstName), lastName(lastName), personalID(personalID), address
               (address) {
    //cout << "Utworzono klienta." << endl;
    //cout << getClientInfo() << endl << endl;
}

const string &Client::getFirstName() const {
    return firstName;
}

void Client::setFirstName(const string &firstName) {
    if (firstName != "")
        Client::firstName = firstName;
}

const string &Client::getLastName() const {
    return lastName;
}

void Client::setLastName(const string &lastName) {
    if (lastName != "")
        Client::lastName = lastName;
}

const string &Client::getPersonalId() const {
    return personalID;
}

const AddressPtr Client::getAddress() const {
    return address;
}

void Client::setAddress(AddressPtr address) {
    if (address != nullptr)
        Client::address = address;
}



