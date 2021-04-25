//
// Created by student on 25.04.2021.
//

#include "managers/VehicleManager.h"

VehiclePtr VehicleManager::getVehicle(std::string Id) {
    return vehicleRepository.findByPlateNumber(Id);
}

VehiclePtr VehicleManager::registerBicycle(std::string plateNumber, int basePrice) {
    if(vehicleRepository.findByPlateNumber(plateNumber)==nullptr)
    {
        BicyclePtr bicycle = std::make_shared<Bicycle>(plateNumber,basePrice);
        vehicleRepository.addVehicle(bicycle);
        return vehicleRepository.findByPlateNumber(plateNumber);
    }
    else
    {
        return vehicleRepository.findByPlateNumber(plateNumber);
    }
}

VehiclePtr VehicleManager::registerMoped(std::string plateNumber, int basePrice, int engineDisplacement) {
    if(vehicleRepository.findByPlateNumber(plateNumber)==nullptr)
    {
        MopedPtr moped = std::make_shared<Moped>(plateNumber,basePrice,engineDisplacement);
        vehicleRepository.addVehicle(moped);
        return vehicleRepository.findByPlateNumber(plateNumber);
    }
    else
    {
        return vehicleRepository.findByPlateNumber(plateNumber);
    }
}

VehiclePtr VehicleManager::registerCar(std::string plateNumber, int basePrice, int engineDisplacement, Car::Segment segmentType) {
    if(vehicleRepository.findByPlateNumber(plateNumber)==nullptr)
    {
        CarPtr car = std::make_shared<Car>(plateNumber,basePrice,engineDisplacement,segmentType);
        vehicleRepository.addVehicle(car);
        return vehicleRepository.findByPlateNumber(plateNumber);
    }
    else
    {
        return vehicleRepository.findByPlateNumber(plateNumber);
    }
}

void VehicleManager::unregisterVehicle(VehiclePtr vehicle) {
    if(vehicleRepository.findByPlateNumber(vehicle->getPlateNumber())!=nullptr)
    {
        vehicle->setArchive(true);
    }
}
std::vector<VehiclePtr> VehicleManager::findVehicles(VehiclePredicate predicate) const {
    auto function = [&](const VehiclePtr &ptr)->bool{return(predicate(ptr)&&!ptr->isArchive());};
    return vehicleRepository.findBy(function);
}
bool predicateTrue(VehiclePtr ptr)
{
    return ptr != nullptr;
}
std::vector<VehiclePtr> VehicleManager::findAllVehicles() const {
    auto function = [&](const VehiclePtr &ptr)->bool{return(predicateTrue(ptr)&&!ptr->isArchive());};
    return vehicleRepository.findBy(function);
}
