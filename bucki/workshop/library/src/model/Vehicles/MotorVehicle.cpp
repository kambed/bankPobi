#include <cmath>
#include "model/Vehicles/MotorVehicle.h"

MotorVehicle::MotorVehicle(const std::string &plateNumber, const unsigned int basePrice,
                           unsigned int engineDisplacement) : Vehicle(plateNumber, basePrice),
                                                              engineDisplacement(engineDisplacement) {}

double MotorVehicle::getActualRentalPrice() {
    if(engineDisplacement<1000)
        return Vehicle::getActualRentalPrice();
    if(engineDisplacement>=1000 && engineDisplacement<=2000)
        return floor((Vehicle::getActualRentalPrice()*((engineDisplacement/2000.0)+0.5)*100.0))/100.0;
    if(engineDisplacement>=2000)
        return Vehicle::getActualRentalPrice()*1.5;
}

MotorVehicle::~MotorVehicle() {}

const std::string MotorVehicle::getVehicleInfo() const {
    return Vehicle::getVehicleInfo() + ", Pojemnosc silnika: " + std::to_string(engineDisplacement);
}
