//
// Created by student on 24.04.2021.
//

#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H


#include "ClientType.h"

class Platinum: public ClientType {
public:
    Platinum();

    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    const std::string getTypeInfo() const override;
};


#endif //CARRENTAL_PLATINUM_H
