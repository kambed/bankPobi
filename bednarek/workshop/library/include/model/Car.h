//
// Created by student on 19.04.2021.
//

#ifndef CARRENTAL_CAR_H
#define CARRENTAL_CAR_H


#include "MotorVehicle.h"

class Car : public MotorVehicle {
public:
    enum Segment{A,B,C,D,E};
private:
    Segment SegmentType;
public:
    Car(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement, Segment segmentType);

    virtual ~Car();

    double getActualRentalPrice();
    const std::string getVehicleInfo() const;

    const std::string getInfo() const override;


public:

};


#endif //CARRENTAL_CAR_H
