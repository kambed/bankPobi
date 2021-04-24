#include <model/Vehicles/Bicycle.h>
#include "repositories/StorageContainer.h"
#include "typedefs.h"
#include "model/Address.h"
#include "model/Client.h"
#include "model/Vehicles/Vehicle.h"
#include "model/Rent.h"
#include "repositories/ClientRepository.h"
#include "repositories/VehicleRepository.h"
#include "repositories/RentRepository.h"

StorageContainer::StorageContainer() {
    AddressPtr address = std::make_shared<Address>("Lodz", "Politechniki", "38");
    ClientPtr client = std::make_shared<Client>("Jan","Kowalski","12345678900", address);
    VehiclePtr vehicle = std::make_shared<Bicycle>("AB1234",10000);
    RentPtr rent = std::make_shared<Rent>(1,client,vehicle,boost::posix_time::not_a_date_time);
    clientsRepo.addClient(client);
    vehiclesRepo.addVehicle(vehicle);
    rentsRepo.addRent(rent);
}

StorageContainer::~StorageContainer(){
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
