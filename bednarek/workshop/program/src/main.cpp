#include <iostream>
#include <vector>
#include <boost/date_time.hpp>
#include <repositories/StorageContainer.h>
#include <repositories/RentRepository.h>
#include <repositories/VehicleRepository.h>
#include <repositories/ClientRepository.h>
#include "model/Client.h"
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "typedefs.h"
using namespace std;
//bool testId1(ClientPtr ptr)
//{
//    return ptr->getPersonalId()=="98765432109";
//}
int main() {
    Address *address = new Address("Lodz","Zielona","23");
    Address *address2 = new Address("Warszawa","Niezielona","12");
    Client *client1 = new Client("Anna","Nowak","98765432109",address);
    Client *client2 = new Client("Jan","Kowalski","95435345539",address2);
    Vehicle *vehicle1 = new Vehicle("EL95353",100);
    Vehicle *vehicle2 = new Vehicle("EL94234",200);
    Rent *rent1 = new Rent(1,client1,vehicle1,boost::posix_time::not_a_date_time,vehicle1->getBasePrice());
    Rent *rent2 = new Rent(2,client1,vehicle2,boost::posix_time::not_a_date_time,vehicle1->getBasePrice());
    rent1->endRent(boost::posix_time::ptime(boost::gregorian::date(2021,5,13),boost::posix_time::hours(9)));
    StorageContainer* st = new StorageContainer();
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
