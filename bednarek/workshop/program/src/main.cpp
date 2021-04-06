#include <iostream>
#include <boost/date_time.hpp>
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
    Address *address2 = new Address("Warszawa","Niezielona","12");
    Client *client1 = new Client("Anna","Nowak","98765432109",address);
    Client *client2 = new Client("Jan","Kowalski","95435345539",address2);
    cout<<client1->getClientInfo()<<endl;
    cout<<client2->getClientInfo()<<endl;
    Vehicle *vehicle1 = new Vehicle("EL95353",100);
    Vehicle *vehicle2 = new Vehicle("EL94234",200);
    Rent *rent1 = new Rent(1,client1,vehicle1,boost::posix_time::not_a_date_time);
    Rent *rent2 = new Rent(2,client1,vehicle2,boost::posix_time::not_a_date_time);
    cout<<rent1->getRentInfo()<<endl;
    cout<<client1->getClientInfo()<<endl;
    cout<<client1->getFullClientInfo()<<endl;
    cout<<vehicle1->isRented()<<endl;
    rent1->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
    cout<<client1->getFullClientInfo()<<endl;
    cout<<vehicle1->isRented()<<endl;
    cout<<rent1->getRentdays()<<endl;
    cout<<rent1->getRentcost()<<endl;
    delete address;
    delete address2;
    delete client1;
    delete client2;
    delete vehicle1;
    delete vehicle2;
    delete rent1;
    delete rent2;
return 0;
}
