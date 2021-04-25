#include <algorithm>
#include "repositories/VehicleRepository.h"
#include "model/Vehicles/Vehicle.h"
#include "typedefs.h"
#include "repositories/RentRepository.h"

VehiclePtr VehicleRepository::getVehicle(unsigned int id) const {
    if (vehicles.size() - 1 < id)
        return nullptr;
    if (vehicles.at(id) == nullptr)
        return nullptr;
    return vehicles.at(id);
}

void VehicleRepository::addVehicle(VehiclePtr vehicle) {
    if (vehicle != nullptr)
        vehicles.push_back(vehicle);
}

void VehicleRepository::removeVehicle(VehiclePtr vehicle) {
    if (vehicle != nullptr)
        vehicles.erase(std::remove(vehicles.begin(), vehicles.end(), vehicle));
}

const std::string VehicleRepository::reportVehicles() const {
//    if(vehicle->isRented())
//        for(int i=0;i<rentRepo.getRentsSize();i++)
//            if(rentRepo.getRent(0)->getVehicle()==vehicle)
//                return rentRepo.getRent(0)->getRentInfo();
//    return "Pojazd nie jest wypozyczony";
    std::string report;
    for (int i = 0; i < vehicles.size(); i++)
        report += vehicles[i]->getVehicleInfo() + "\n";
    return report;
}

unsigned int VehicleRepository::getVehiclesSize() {
    return vehicles.size();
}

std::vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) const {
    std::vector<VehiclePtr> found;
    for (unsigned int i = 0; i < vehicles.size(); i++) {
        VehiclePtr vehicle = getVehicle(i);
        if (vehicle != nullptr && predicate(vehicle)) {
            found.push_back(vehicle);
        }
    }
    return found;
}

bool predicateTrue(VehiclePtr vehicle){
    return vehicle != nullptr;
}

std::vector<VehiclePtr> VehicleRepository::findAll() const{
    return VehicleRepository::findBy(predicateTrue);
}

VehiclePtr VehicleRepository::findByPlateNumber(std::string plateNumber) const {
    for (unsigned int i = 0; i < vehicles.size(); i++) {
        VehiclePtr vehicle = getVehicle(i);
        if (vehicle->getPlateNumber() == plateNumber)
            return vehicle;
    }
    return nullptr;
}