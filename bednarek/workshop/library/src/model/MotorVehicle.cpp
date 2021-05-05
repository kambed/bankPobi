//
// Created by student on 19.04.2021.
//

#include "model/MotorVehicle.h"

MotorVehicle::MotorVehicle(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement) : Vehicle(
        plateNumber, basePrice), engineDisplacement(engineDisplacement) {}
MotorVehicle::~MotorVehicle() {

}
double MotorVehicle::getActualRentalPrice() {
    double fac=0;
    if(engineDisplacement<1000){
        fac=1.0;
    }
    if(engineDisplacement>2000){
        fac=1.5;
    }
    if(engineDisplacement>=1000 && engineDisplacement<=2000){
        fac=(engineDisplacement*0.0005)+0.5;
    }
    return Vehicle::getActualRentalPrice()*fac;
}

const std::string MotorVehicle::getVehicleInfo() const {
    return Vehicle::getVehicleInfo() + " Pojemnosc silnika: " + std::to_string(engineDisplacement);
}

const std::string MotorVehicle::getInfo() const {
    return Vehicle::getInfo();
}
