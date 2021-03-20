#include <iostream>
#include <model/Client.h>

using namespace std;

int main() {
    //etap 0 i 2
    Client client("Jan","Kowalski","00112233445");
    Client *client2 = new Client("Mariusz","Nowak","11223344556");
    //etap 1
    cout << client.getClientInfo() << endl << endl;
    cout << client2->getClientInfo() << endl << endl;
    //etap 3
    client.setFirstName("");
    client.getClientInfo();
    client.setFirstName("Janusz");
    client.getClientInfo();
    //etap 0
    delete client2;
    return 0;
}
