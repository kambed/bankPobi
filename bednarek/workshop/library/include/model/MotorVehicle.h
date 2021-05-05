//
// Created by student on 19.04.2021.
//

#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H


#include "Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    int engineDisplacement;
public:
    MotorVehicle(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement);
    virtual ~MotorVehicle()=0;
    virtual double getActualRentalPrice();
    virtual const std::string getVehicleInfo() const;

    const std::string getInfo() const override;
};


#endif //CARRENTAL_MOTORVEHICLE_H
