#include "model/Vehicles/Moped.h"

Moped::Moped(const std::string &plateNumber, const unsigned int basePrice, unsigned int engineDisplacement)
        : MotorVehicle(plateNumber, basePrice, engineDisplacement) {}


Moped::~Moped() {}