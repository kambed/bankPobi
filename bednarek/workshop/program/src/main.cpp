#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
using namespace std;
int main() {
//    Client *client3 = new Client("Anna","Nowak","98765432109",nullptr);
//    Address *address3 = new Address("Lodz","Zielona","23");
//    client3->setAddress(address3);
//    cout<<client3->getClientInfo()<<endl;
//    delete address3;
//    delete client3;

    Address *address = new Address("Lodz","Zielona","23");
    Client *client1 = new Client("Anna","Nowak","98765432109",address);
    Client *client2 = new Client("Jan","Kowalski","95435345539",address);
    //client1->getAddress()->setCity("Warszawa");
    Address *address2 = new Address("Warszawa","Niezielona","12");
    client1->setAddress(address2);
    cout<<client1->getClientInfo()<<endl;
    cout<<client2->getClientInfo()<<endl;

    return 0;
}
