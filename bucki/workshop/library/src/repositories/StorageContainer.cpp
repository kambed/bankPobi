#include <model/Bicycle.h>
#include "repositories/StorageContainer.h"
#include "typedefs.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Vehicle.h"
#include "model/Rent.h"
#include "repositories/ClientRepository.h"
#include "repositories/VehicleRepository.h"
#include "repositories/RentRepository.h"

StorageContainer::StorageContainer() {
    address = new Address("Lodz", "Politechniki", "38");
    client = new Client("Jan","Kowalski","12345678900", address);
    vehicle = new Bicycle("AB1234",10000);
    rent = new Rent(1,client,vehicle,boost::posix_time::not_a_date_time);
    clientsRepo.addClient(client);
    vehiclesRepo.addVehicle(vehicle);
    rentsRepo.addRent(rent);
}

StorageContainer::~StorageContainer(){
    delete address;
    delete client;
    delete vehicle;
    delete rent;
}

ClientRepository &StorageContainer::getClientsRepo(){
    return clientsRepo;
}

RentRepository &StorageContainer::getRentsRepo(){
    return rentsRepo;
}

VehicleRepository &StorageContainer::getVehiclesRepo(){
    return vehiclesRepo;
}