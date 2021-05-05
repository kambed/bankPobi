//
// Created by student on 19.04.2021.
//

#include "model/Bicycle.h"

Bicycle::Bicycle(const std::string &plateNumber, unsigned int basePrice) : Vehicle(plateNumber, basePrice) {}
Bicycle::~Bicycle() {

}
double Bicycle::getActualRentalPrice() {
    return Vehicle::getActualRentalPrice();
}

const std::string Bicycle::getVehicleInfo() const {
    return Vehicle::getVehicleInfo();
}

const std::string Bicycle::getInfo() const {
    return Vehicle::getInfo();
}
