//
// Created by student on 24.04.2021.
//

#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H


#include "ClientType.h"

class Default: public ClientType {
public:
    Default();

    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    const std::string getTypeInfo() const override;
};


#endif //CARRENTAL_DEFAULT_H
