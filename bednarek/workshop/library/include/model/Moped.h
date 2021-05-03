//
// Created by student on 19.04.2021.
//

#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H


#include "MotorVehicle.h"

class Moped : public MotorVehicle {
public:
    Moped(const std::string &plateNumber, unsigned int basePrice, int engineDisplacement);

    virtual ~Moped();

    double getActualRentalPrice();
    const std::string getVehicleInfo() const;
    const std::string getInfo() const override;
};


#endif //CARRENTAL_MOPED_H
