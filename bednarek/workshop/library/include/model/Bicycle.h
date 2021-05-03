//
// Created by student on 19.04.2021.
//

#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    Bicycle(const std::string &plateNumber, unsigned int basePrice);
    virtual ~Bicycle();

    double getActualRentalPrice();
    const std::string getVehicleInfo() const;

    const std::string getInfo() const override;
};


#endif //CARRENTAL_BICYCLE_H
