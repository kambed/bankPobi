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
    /// GETTERS

    /// \param id
    /// \return
    VehiclePtr getVehicle(unsigned int id);

    /// \return
    unsigned int getVehiclesSize();

    /// METHODS

    /// \param vehicle
    void addVehicle(VehiclePtr vehicle);

    /// \param vehicle
    void removeVehicle(VehiclePtr vehicle);

    /// \return
    const std::string reportVehicles();

    /// \param predicate
    /// \return
    std::vector<VehiclePtr> findBy(VehiclePredicate predicate);

    /// \return
    std::vector<VehiclePtr> findAll();

    /// \param plateNumber
    /// \return
    VehiclePtr findByPlateNumber(std::string plateNumber);
};


#endif //CARRENTAL_VEHICLEREPOSITORY_H
