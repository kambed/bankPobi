#include "model/vehicles/Vehicle.h"
#include <iostream>
#include "model/Vehicles/Vehicle.h"
#include "exceptions/VehicleException.h"

Vehicle::Vehicle(const std::string &plateNumber, const unsigned int basePrice) try : plateNumber(plateNumber),
                                                                                 basePrice(basePrice) {
    if(basePrice<=0) throw VehicleException("BasePrice must be greater than 0");
    if(plateNumber.empty()) throw VehicleException("PlateNumber is empty");
}
catch(const VehicleException &exception){
    std::cout <<" Exception: " << exception.what() << std::endl;
}

const std::string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

//void Vehicle::setPlateNumber(const std::string &plateNumber) {
//    if (plateNumber != "")
//        Vehicle::plateNumber = plateNumber;
//}

const unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

void Vehicle::setBasePrice(const unsigned int basePrice) {
    Vehicle::basePrice = basePrice;
}

const std::string Vehicle::getVehicleInfo() const {
    return plateNumber + ", cena: " + std::to_string(basePrice);
}

double Vehicle::getActualRentalPrice() {
    return basePrice;
}

Vehicle::~Vehicle() {}

bool Vehicle::isArchive() const {
    return archive;
}

void Vehicle::setArchive(bool archive) {
    Vehicle::archive = archive;
}
