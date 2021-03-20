//
// Created by student on 20.03.2021.
//

#include <iostream>
#include <string>
#include "model/Client.h"
using namespace std;

Client::Client() {

}
Client::Client(std::string firstName,std::string lastName,std::string personalID) : firstName(firstName), lastName(lastName), personalID(personalID) {

};
Client::~Client() {

}

std::string Client::getClientInfo() {
    return "Client:" + firstName + " " + lastName + " " + personalID;
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
