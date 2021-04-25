#ifndef CARRENTAL_MOPED_H
#define CARRENTAL_MOPED_H


#include "MotorVehicle.h"

class Moped : public MotorVehicle {
public:
    Moped(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement);

    ~Moped();
};


#endif //CARRENTAL_MOPED_H
