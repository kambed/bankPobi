#include <iostream>
#include "model/Client.h"

using namespace std;

Client::Client() {
    cout << "Utworzono klienta." << endl;
}

Client::~Client() {
    cout << "Usunieto klienta" << endl;
}

string Client::getClientInfo() {
    return "Client: "+firstName+" "+lastName+" "+personalID;
}


