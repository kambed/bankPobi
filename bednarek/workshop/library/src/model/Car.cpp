//
// Created by student on 19.04.2021.
//

#include "model/Car.h"

Car::Car(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement, Car::Segment segmentType)
        : MotorVehicle(plateNumber, basePrice, engineDisplacement), SegmentType(segmentType) {}
Car::~Car() {

}
double Car::getActualRentalPrice() {
    double fac;
    switch(SegmentType)
    {
        case A:
            fac=1.0;
            break;
        case B:
            fac=1.1;
            break;
        case C:
            fac=1.2;
            break;
        case D:
            fac=1.3;
            break;
        case E:
            fac=1.5;
            break;
        default:
            fac=0.0;
            break;
    }
    return MotorVehicle::getActualRentalPrice()*fac;
}

const std::string Car::getVehicleInfo() const {
    std::string cls;
    switch(SegmentType)
    {
        case A:
            cls="A";
            break;
        case B:
            cls="B";
            break;
        case C:
            cls="C";
            break;
        case D:
            cls="D";
            break;
        case E:
            cls="E";
            break;
        default:
            cls="X";
            break;
    }
    return MotorVehicle::getVehicleInfo() + " Klasa: " + cls;
}
const std::string Car::getInfo() const {
    return MotorVehicle::getInfo();
}
