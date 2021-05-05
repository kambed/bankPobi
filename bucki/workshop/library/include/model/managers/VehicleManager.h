#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H


#include "typedefs.h"
#include <vector>
#include <model/vehicles/Car.h>

class VehicleManager {
private:
    VehicleRepositoryPtr vehicleRepository;
public:
    VehicleManager();

    VehiclePtr getVehicle(std::string plateNumber);

    VehiclePtr registerBicycle(const std::string &plateNumber, const unsigned int basePrice);
    VehiclePtr registerMoped(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement);
    VehiclePtr registerCar(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement,
                           Car::Segment segmentType);

    void unregisterVehicle(std::string plateNumber);

    std::vector<VehiclePtr> findVehicles(VehiclePredicate predicate) const;

    std::vector<VehiclePtr> findAllVehicles() const;
};


#endif //CARRENTAL_VEHICLEMANAGER_H
