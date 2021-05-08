#ifndef CARRENTAL_BICYCLE_H
#define CARRENTAL_BICYCLE_H


#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    /// CONSTRUCTOR

    /// \param plateNumber
    /// \param basePrice
    Bicycle(const std::string &plateNumber, const unsigned int basePrice);
};


#endif //CARRENTAL_BICYCLE_H
