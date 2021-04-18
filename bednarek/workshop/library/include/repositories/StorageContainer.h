//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_STORAGECONTAINER_H
#define CARRENTAL_STORAGECONTAINER_H


#include <typedefs.h>
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/VehicleRepository.h"

class StorageContainer {
private:
    VehicleRepository vehiclerepository;
    RentRepository rentrepository;
    ClientRepository clientrepository;
public:
    StorageContainer();
    VehicleRepository &getVehiclerepository();
    RentRepository &getRentrepository();
    ClientRepository &getClientrepository();
};


#endif //CARRENTAL_STORAGECONTAINER_H
