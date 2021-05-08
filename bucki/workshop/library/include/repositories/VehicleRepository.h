#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H


#include <vector>
#include "typedefs.h"
#include <string>
#include "repositories/RentRepository.h"
#include "repositories/Repository.h"

class VehicleRepository : public Repository<Vehicle> {
private:
    std::vector<VehiclePtr> vehicles;
public:


    VehiclePtr getVehicle(unsigned int id);

    void addVehicle(VehiclePtr vehicle);

    void removeVehicle(VehiclePtr vehicle);

    const std::string reportVehicles();

    unsigned int getVehiclesSize();

    std::vector<VehiclePtr> findBy(VehiclePredicate predicate);

    std::vector<VehiclePtr> findAll();

    VehiclePtr findByPlateNumber(std::string plateNumber);
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
