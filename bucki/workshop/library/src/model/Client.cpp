#include <iostream>
#include "model/Client.h"

using namespace std;

Client::Client() {
    //cout << "Utworzono klienta." << endl << endl;
}

Client::~Client() {
    //cout << "Usunieto klienta" << endl;
    //cout << getClientInfo() << endl << endl;
}

string Client::getClientInfo() {
    return "Client: " + firstName + " " + lastName + " " + personalID;
}

Client::Client(std::string firstName, std::string lastName, std::string personalID) : firstName(firstName),lastName(lastName),personalID(personalID){
    //cout << "Utworzono klienta." << endl;
    //cout << getClientInfo() << endl << endl;
}

const string &Client::getFirstName() const {
    return firstName;
}

void Client::setFirstName(const string &firstName) {
    if(firstName!="")
        Client::firstName = firstName;
}

const string &Client::getLastName() const {
    return lastName;
}

void Client::setLastName(const string &lastName) {
    if(lastName!="")
        Client::lastName = lastName;
}

const string &Client::getPersonalId() const {
    return personalID;
}



