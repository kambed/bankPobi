#include <memory>
#include <functional>
#include "model/managers/VehicleManager.h"
#include "typedefs.h"
#include "model/vehicles/Vehicle.h"
#include "model/vehicles/Bicycle.h"
#include "model/vehicles/Moped.h"
#include "model/vehicles/MotorVehicle.h"
#include "model/vehicles/Car.h"
#include "repositories/VehicleRepository.h"

VehicleManager::VehicleManager() {
    vehicleRepository = std::make_shared<VehicleRepository>();
}

VehicleManager::VehicleManager(const VehicleRepositoryPtr &vehicleRepository) : vehicleRepository(vehicleRepository) {}

VehiclePtr VehicleManager::getVehicle(std::string plateNumber) {
    return vehicleRepository->findByPlateNumber(plateNumber);
}

VehiclePtr VehicleManager::registerBicycle(const std::string &plateNumber, const unsigned int basePrice) {
    if (vehicleRepository->findByPlateNumber(plateNumber) != nullptr)
        return vehicleRepository->findByPlateNumber(plateNumber);
    else {
        VehiclePtr vehicle = std::make_shared<Bicycle>(plateNumber,basePrice);
        vehicleRepository->addVehicle(vehicle);
        return vehicle;
    }
}

VehiclePtr VehicleManager::registerMoped(const std::string &plateNumber, const unsigned int basePrice,
                                         unsigned int engineDisplacement) {
    if (vehicleRepository->findByPlateNumber(plateNumber) != nullptr)
        return vehicleRepository->findByPlateNumber(plateNumber);
    else {
        VehiclePtr vehicle = std::make_shared<Moped>(plateNumber,basePrice,engineDisplacement);
        vehicleRepository->addVehicle(vehicle);
        return vehicle;
    }
}

VehiclePtr VehicleManager::registerCar(const std::string &plateNumber, const unsigned int basePrice,
                                       unsigned int engineDisplacement, Car::Segment segmentType) {
    if (vehicleRepository->findByPlateNumber(plateNumber) != nullptr)
        return vehicleRepository->findByPlateNumber(plateNumber);
    else {
        VehiclePtr vehicle = std::make_shared<Car>(plateNumber,basePrice,engineDisplacement,segmentType);
        vehicleRepository->addVehicle(vehicle);
        return vehicle;
    }
}

void VehicleManager::unregisterVehicle(std::string plateNumber) {
    if (getVehicle(plateNumber) != nullptr)
        getVehicle(plateNumber)->setArchive(true);
}

std::vector<VehiclePtr> VehicleManager::findVehicles(VehiclePredicate predicate) const {
    auto function = [&](const VehiclePtr vehicle) -> bool {
        return (predicate(vehicle) && vehicle->isArchive()) == false;
    };

    return vehicleRepository->findBy(function);
}

bool predicateTrueManager(VehiclePtr client){
    return client != nullptr;
}

std::vector<VehiclePtr> VehicleManager::findAllVehicles() const {
    return findVehicles(predicateTrueManager);
}
