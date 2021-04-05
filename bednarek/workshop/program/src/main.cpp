#include <iostream>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
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
    Vehicle *vehicle1 = new Vehicle("EL95353",100);
    Rent *rent1 = new Rent(1,client1,vehicle1);
    Rent *rent2 = new Rent(2,client1,vehicle1);
    cout<<rent1->getRentInfo()<<endl;
    cout<<client1->getClientInfo()<<endl;
    cout<<client1->getFullClientInfo()<<endl;
    cout<<client1->getCurrentRents();
    delete address;
    delete client1;
    delete client2;
    delete vehicle1;
    delete rent1;

    return 0;
}
