#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H

#include "Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    unsigned int engineDisplacement;
public:
    MotorVehicle(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement);

    virtual ~MotorVehicle();

    const std::string getVehicleInfo() const override;

    double getActualRentalPrice() override;
};


#endif //CARRENTAL_MOTORVEHICLE_H
