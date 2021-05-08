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
    /// CONSTRUCTOR

    /// \param plateNumber
    /// \param basePrice
    /// \param engineDisplacement
    /// \param segmentType
    Car(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement,
        Segment segmentType);

    /// DESTRUCTOR

    ~Car();

    /// GETTERS

    /// \return
    double getActualRentalPrice() override;

    /// \return
    const std::string getVehicleInfo() const override;
};


#endif //CARRENTAL_CAR_H
