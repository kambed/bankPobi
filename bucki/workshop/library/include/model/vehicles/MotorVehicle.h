#ifndef CARRENTAL_MOTORVEHICLE_H
#define CARRENTAL_MOTORVEHICLE_H

#include "Vehicle.h"

class MotorVehicle : public Vehicle {
private:
    unsigned int engineDisplacement;
public:
    /// CONSTRUCTOR

    /// \param plateNumber
    /// \param basePrice
    /// \param engineDisplacement
    MotorVehicle(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement);

    /// DESTRUCTOR

    virtual ~MotorVehicle();

    /// GETTERS

    /// \return
    const std::string getVehicleInfo() const override;

    /// \return
    double getActualRentalPrice() override;
};


#endif //CARRENTAL_MOTORVEHICLE_H
