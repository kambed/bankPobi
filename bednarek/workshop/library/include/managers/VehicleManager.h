//
// Created by student on 25.04.2021.
//

#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H

#include <typedefs.h>
#include <repositories/VehicleRepository.h>

class VehicleManager {
private:
    VehicleRepository vehicleRepository;
public:
    VehiclePtr getVehicle(std::string Id);
    VehiclePtr registerBicycle(std::string plateNumber,int basePrice);
    VehiclePtr registerMoped(std::string plateNumber,int basePrice,int engineDisplacement);
    VehiclePtr registerCar(std::string plateNumber,int basePrice,int engineDisplacement,Car::Segment segmentType);
    void unregisterVehicle(VehiclePtr vehicle);
    std::vector<VehiclePtr> findVehicles(VehiclePredicate predicate) const;
    std::vector<VehiclePtr> findAllVehicles() const;
};


#endif //CARRENTAL_VEHICLEMANAGER_H
