//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_VEHICLEREPOSITORY_H
#define CARRENTAL_VEHICLEREPOSITORY_H
#include "../model/Vehicle.h"
#include "../typedefs.h"
#include <string>
#include <vector>

class VehicleRepository {
private:
    std::vector<VehiclePtr> Vehicles;
public:
    VehiclePtr getVehicle(int vehicleIndex) const;
    void addVehicle(VehiclePtr vehicle);
    void removeVehicle(VehiclePtr vehicle);
    std::string reportVehicle(VehiclePtr vehicle) const;
    int sizeVehicle() const;
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
