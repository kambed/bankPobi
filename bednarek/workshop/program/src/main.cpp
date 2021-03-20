#include <iostream>
#include "model/Client.h"
using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    Client client("Jan","Kowalski","12345678901");
    Client *client2 = new Client("Anna","Nowak","98765432109");
    cout<< client.getClientInfo() <<endl;
    cout<< client2->getClientInfo() <<endl;
    client.setFirstName("");
    cout<< client.getClientInfo() <<endl;
    client.setFirstName("Mariusz");
    cout<< client.getClientInfo() <<endl;
    delete client2;
    return 0;
}
