#ifndef CARRENTAL_VEHICLEMANAGER_H
#define CARRENTAL_VEHICLEMANAGER_H


#include "typedefs.h"
#include <vector>
#include <model/vehicles/Car.h>

class VehicleManager {
private:
    VehicleRepositoryPtr vehicleRepository;
public:
    /// CONSTRUCTOR

    VehicleManager();

    /// GETTERS

    /// \param plateNumber
    /// \return
    VehiclePtr getVehicle(std::string plateNumber);
    /// \param plateNumber
    /// \param basePrice
    /// \return

    /// METHODS

    VehiclePtr registerBicycle(const std::string &plateNumber, const unsigned int basePrice);

    /// \param plateNumber
    /// \param basePrice
    /// \param engineDisplacement
    /// \return
    VehiclePtr registerMoped(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement);

    /// \param plateNumber
    /// \param basePrice
    /// \param engineDisplacement
    /// \param segmentType
    /// \return
    VehiclePtr registerCar(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement,
                           Car::Segment segmentType);

    /// \param plateNumber
    void unregisterVehicle(std::string plateNumber);

    /// \param predicate
    /// \return
    std::vector<VehiclePtr> findVehicles(VehiclePredicate predicate) const;

    /// \return
    std::vector<VehiclePtr> findAllVehicles() const;
};


#endif //CARRENTAL_VEHICLEMANAGER_H
