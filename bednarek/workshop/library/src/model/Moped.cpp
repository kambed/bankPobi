//
// Created by student on 19.04.2021.
//

#include "model/Moped.h"

Moped::Moped(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement) : MotorVehicle(plateNumber,
                                                                                                            basePrice,
                                                                                                            engineDisplacement) {}
Moped::~Moped() {

}
double Moped::getActualRentalPrice() {
    return MotorVehicle::getActualRentalPrice();
}

const std::string Moped::getVehicleInfo() const {
    return MotorVehicle::getVehicleInfo();
}

