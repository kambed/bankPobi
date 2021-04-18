#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H


#include <vector>
#include "typedefs.h"
#include <string>
#include "repositories/RentRepository.h"

class VehicleRepository {
private:
    std::vector<VehiclePtr> vehicles;
public:


    VehiclePtr getVehicle(unsigned int id) const;

    void addVehicle(VehiclePtr vehicle);

    void removeVehicle(VehiclePtr vehicle);

    const std::string reportVehicles() const;

    unsigned int getVehiclesSize();

    std::vector<VehiclePtr> findBy(VehiclePredicate predicate) const;
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
