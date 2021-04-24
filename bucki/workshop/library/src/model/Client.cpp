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

const string Client::getFullClientInfo() const {
    string rentlist = "";
    for (int i = 0; i < currentRents.size(); i++)
        rentlist += "\n" + currentRents[i]->getRentInfo();
    return firstName + " " + lastName + " " + personalID + ", adres:" + address->getAddressInfo() + rentlist;
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

const std::vector<RentPtr> &Client::getCurrentRents() const {
    return currentRents;
}

void Client::addRent(RentPtr rent) {
    currentRents.push_back(rent);
}

void Client::removeRent(RentPtr rent) {
    currentRents.erase(std::remove(currentRents.begin(), currentRents.end(), rent));
}



