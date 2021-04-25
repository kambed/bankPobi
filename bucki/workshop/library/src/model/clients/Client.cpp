#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <model/Clients/ClientType.h>
#include "model/Clients/Client.h"

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
    return firstName + " " + lastName + " " + personalID + ", adres:" + address->getAddressInfo() + ", \ntyp klienta: "
           + clientType->getTypeInfo();
}

Client::Client(const std::string &firstName, const std::string &lastName, const std::string &personalID,
               AddressPtr address, ClientTypePtr clientType) : firstName(firstName), lastName(lastName), personalID
        (personalID), address(address), clientType(clientType) {

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

void Client::setAddress(shared_ptr <Address> address) {
    if (address != nullptr)
        Client::address = address;
}

void Client::setClientType(shared_ptr <ClientType> clientType) {
    Client::clientType = clientType;
}

const int Client::getMaxVehicles() const {
    return clientType->getMaxVehicles();
}

const double Client::applyDiscount(double price) const {
    return float(clientType->applyDiscount(price) * 100) / 100;
}

bool Client::isArchive() const {
    return archive;
}

void Client::setArchive(bool archive) {
    Client::archive = archive;
}



