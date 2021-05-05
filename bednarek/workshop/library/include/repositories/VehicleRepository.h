//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include "../model/Vehicle.h"
#include "../typedefs.h"
#include <string>
#include <vector>
#include "repositories/Repository.h"

class VehicleRepository : public Repository<Vehicle>{
private:
    std::vector<VehiclePtr> Vehicles;
public:
    VehiclePtr getVehicle(int vehicleIndex) const;
    void addVehicle(VehiclePtr vehicle);
    void removeVehicle(VehiclePtr vehicle);
    std::string reportVehicle() const;
    int sizeVehicle() const;
    std::vector<VehiclePtr> findBy(VehiclePredicate predicate) const;
    std::vector<VehiclePtr> findAll();
    VehiclePtr findByPlateNumber(std::string plateNumber);
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
