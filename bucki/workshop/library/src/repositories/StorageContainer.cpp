#include <model/vehicles/Bicycle.h>
#include <model/clients/Bronze.h>
#include "repositories/StorageContainer.h"
#include "typedefs.h"
#include "model/Address.h"
#include "model/clients/Client.h"
#include "model/vehicles/Vehicle.h"
#include "model/Rent.h"
#include "repositories/ClientRepository.h"
#include "repositories/VehicleRepository.h"
#include "repositories/RentRepository.h"

StorageContainer::StorageContainer() {
    AddressPtr address = std::make_shared<Address>("Lodz", "Politechniki", "38");
    ClientTypePtr bronze = std::make_shared<Bronze>();
    ClientPtr client = std::make_shared<Client>("Jan", "Kowalski", "12345678900", address, bronze);
    VehiclePtr vehicle = std::make_shared<Bicycle>("AB1234", 10000);
    boost::uuids::random_generator generator;
    RentPtr rent = std::make_shared<Rent>(generator(), client, vehicle, boost::posix_time::not_a_date_time);
    clientsRepo.addClient(client);
    vehiclesRepo.addVehicle(vehicle);
    rentsRepo.addRent(rent);
}

StorageContainer::~StorageContainer() {
}

ClientRepository &StorageContainer::getClientsRepo() {
    return clientsRepo;
}

RentRepository &StorageContainer::getRentsRepo() {
    return rentsRepo;
}

VehicleRepository &StorageContainer::getVehiclesRepo() {
    return vehiclesRepo;
}
