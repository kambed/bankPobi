#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H


#include "MotorVehicle.h"

class Moped : public MotorVehicle {
public:
    /// CONSTRUCTOR

    Moped(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement);

    /// DESTRUCTOR

    ~Moped();
};


#endif //CARRENTAL_MOPED_H
