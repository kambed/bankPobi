#include <model/Vehicles/MotorVehicle.h>
#include <cmath>
#include "model/Vehicles/Car.h"

Car::Car(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement,
         Car::Segment segmentType) : MotorVehicle(plateNumber, basePrice, engineDisplacement),
                                     SegmentType(segmentType) {}

double Car::getActualRentalPrice() {
    return floor(MotorVehicle::getActualRentalPrice() * (1 + (SegmentType / 10.0)) * 100.0) / 100.0;
}

Car::~Car() {}

const std::string Car::getVehicleInfo() const {
    return MotorVehicle::getVehicleInfo() + ", Segment: " + std::to_string(SegmentType);
}


