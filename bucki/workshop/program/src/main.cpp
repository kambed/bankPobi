#include <iostream>
#include <model/Client.h>

int main() {
    Client client;
    Client *client2 = new Client;

    delete client2;
    return 0;
}
