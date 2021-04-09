//
// Created by student on 05.04.2021.
//

#include <iostream>
#include <string>
#include "model/Vehicle.h"

Vehicle::Vehicle(const std::string &plateNumber, unsigned int basePrice) : plateNumber(plateNumber),
                                                                           basePrice(basePrice) {}

const std::string &Vehicle::getPlateNumber() const {
    return plateNumber;
}

void Vehicle::setPlateNumber(const std::string &plateNumber) {
    if(plateNumber!="") {
        Vehicle::plateNumber = plateNumber;
    }
}

unsigned int Vehicle::getBasePrice() const {
    return basePrice;
}

void Vehicle::setBasePrice(unsigned int basePrice) {
    Vehicle::basePrice = basePrice;
}

const std::string Vehicle::getVehicleInfo() const{
    return "Pojazd:" + plateNumber + " " + std::to_string(basePrice) + "zl/h";
}

bool Vehicle::isRented() const {
    return rented;
}

void Vehicle::setRented(bool rented) {
    Vehicle::rented = rented;
}
