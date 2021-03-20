#include <iostream>
#include "model/Client.h"

using namespace std;

Client::Client() {
    cout << "Utworzono klienta." << endl << endl;
}

Client::~Client() {
    cout << "Usunieto klienta" << endl << endl;
}

string Client::getClientInfo() {
    return "Client: " + firstName + " " + lastName + " " + personalID;
}

Client::Client(std::string firstName, std::string nastName, std::string personalID) : firstName(firstName),lastName(lastName),personalID(personalID){
    cout << "Utworzono klienta." << endl;
    cout << getClientInfo() << endl << endl;
}



