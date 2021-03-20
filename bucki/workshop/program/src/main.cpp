#include <iostream>
#include <model/Client.h>

using namespace std;

int main() {
    //etap 0
    Client client;
    Client *client2 = new Client;
    //etap 1
    cout << client.getClientInfo() << endl;
    cout << client2->getClientInfo() << endl;
    //etap 0
    delete client2;
    return 0;
}
