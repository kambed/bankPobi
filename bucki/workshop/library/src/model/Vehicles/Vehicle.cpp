#include "model/Vehicles/Vehicle.h"

Vehicle::Vehicle(const std::string &plateNumber, const unsigned int basePrice) : plateNumber(plateNumber),
                                                                           basePrice(basePrice) {}

const std::string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

void Vehicle::setPlateNumber(const std::string &plateNumber) {
    if(plateNumber != "")
        Vehicle::plateNumber = plateNumber;
}

const unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

void Vehicle::setBasePrice(const unsigned int basePrice) {
    Vehicle::basePrice = basePrice;
}

const std::string Vehicle::getVehicleInfo() const{
    return plateNumber + ", cena: " + std::to_string(basePrice);
}

double Vehicle::getActualRentalPrice() {
    return basePrice;
}

Vehicle::~Vehicle() {}
