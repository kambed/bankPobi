#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H


#include "typedefs.h"
#include "ClientRepository.h"
#include "RentRepository.h"
#include "VehicleRepository.h"

class StorageContainer {
private:
    VehiclePtr vehicle;
    ClientPtr client;
    AddressPtr address;
    RentPtr rent;
    ClientRepository clientsRepo;
    RentRepository rentsRepo;
    VehicleRepository vehiclesRepo;
public:
    StorageContainer();

    ~StorageContainer();

    ClientRepository &getClientsRepo();

    RentRepository &getRentsRepo();

    VehicleRepository &getVehiclesRepo();
};


#endif //CARRENTAL_STORAGECONTAINER_H
