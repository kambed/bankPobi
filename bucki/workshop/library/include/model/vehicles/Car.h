#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H


#include "Vehicle.h"
#include "MotorVehicle.h"

class Car : public MotorVehicle {
public:
    enum Segment {
        A = 0, B = 1, C = 2, D = 3, E = 5
    };
private:
    Segment SegmentType;
public:
    Car(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement,
        Segment segmentType);

    ~Car();

    double getActualRentalPrice() override;

    const std::string getVehicleInfo() const override;
};


#endif //CARRENTAL_CAR_H
