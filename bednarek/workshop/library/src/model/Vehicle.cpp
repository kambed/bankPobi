//
// Created by student on 05.04.2021.
//

#include <iostream>
#include <string>
#include "model/Vehicle.h"
//CONSTRUCTOR
Vehicle::Vehicle(const std::string &plateNumber, unsigned int basePrice) : plateNumber(plateNumber),
                                                                           basePrice(basePrice) {}
//DESTRUCTOR
Vehicle::~Vehicle() {

}
//GETTERS
const std::string &Vehicle::getPlateNumber() const {
    return plateNumber;
}
unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}
const std::string Vehicle::getVehicleInfo() const{
    return "Pojazd:" + plateNumber + " " + std::to_string(basePrice) + "zl/day";
}

//SETTERS
void Vehicle::setPlateNumber(const std::string &plateNumber) {
    if(plateNumber!="") {
        Vehicle::plateNumber = plateNumber;
    }
}
void Vehicle::setBasePrice(unsigned int basePrice) {
    Vehicle::basePrice = basePrice;
}

double Vehicle::getActualRentalPrice() {
    return getBasePrice();
}

bool Vehicle::isArchive() const {
    return archive;
}

void Vehicle::setArchive(bool archive) {
    Vehicle::archive = archive;
}
