#include <iostream>
#include <string>
#include <model/Client.h>
#include <model/Address.h>

using namespace std;

int main() {
//Warsztaty1
//    //etap 0 i 2
//    Client client("Jan","Kowalski","00112233445");
//    Client *client2 = new Client("Mariusz","Nowak","11223344556");
//    //etap 1
//    cout << client.getClientInfo() << endl << endl;
//    cout << client2->getClientInfo() << endl << endl;
//    //etap 3
//    client.setFirstName("");
//    cout << client.getClientInfo() << endl;
//    client.setFirstName("Janusz");
//    cout << client.getClientInfo() << endl;
//    //etap 0
//    delete client2;

//Warsztaty3
//    Client *client=new Client("Jan","Kowalski","00112233445", nullptr);
//    Address *address=new Address("Lodz","Politechniki","38");
//    client->setAddress(address);
//    cout << "Client: " << client->getClientInfo() << endl;
//    cout << "Adres: " << address->getAddressInfo();
//    delete client;
//    delete address;

//    Address *address1 = new Address("Lodz","Politechniki","38");
//    Client *client1 = new Client("Jan","Kowalski","00000000000", address1);
//    Client *client2 = new Client("Adam","Nowak","00000000001", address1);
//    Address *address2 = new Address("Pabianice","Wiejska","2");
//    client2->setAddress(address2);
//    cout << client1->getClientInfo() << endl;
//    cout << client2->getClientInfo() << endl;
//    delete client1;
//    delete client2;
//    delete address1;
//    delete address2;
    Address address("Lodz", "Politechniki", "38");
    Client client("Jan", "Kowalski", "00000000000", &address);
    Vehicle vehicle("AB1234", 10000);
    Rent rent(1, &client, &vehicle,boost::posix_time::not_a_date_time);
    cout << rent.getRentInfo();

    return 0;
}
