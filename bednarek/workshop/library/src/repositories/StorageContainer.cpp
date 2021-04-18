//
// Created by student on 18.04.2021.
//

#include "repositories/StorageContainer.h"
#include "model/Rent.h"
#include "typedefs.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Address.h"

StorageContainer::StorageContainer(){
    Address *address = new Address("Lodz","Zielona","23");
    Client *client1 = new Client("Anna","Nowak","98765432109",address);
    Vehicle *vehicle1 = new Vehicle("EL95353",100);
    Rent *rent1 = new Rent(1,client1,vehicle1,boost::posix_time::not_a_date_time,vehicle1->getBasePrice());
    clientrepository.addClient(client1);
    vehiclerepository.addVehicle(vehicle1);
    rentrepository.addRent(rent1);
}

VehicleRepository &StorageContainer::getVehiclerepository() {
    return vehiclerepository;
}

RentRepository &StorageContainer::getRentrepository() {
    return rentrepository;
}

ClientRepository &StorageContainer::getClientrepository() {
    return clientrepository;
}
