//
// Created by student on 24.04.2021.
//

#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H


#include "ClientType.h"

class Bronze: public ClientType {
public:
    Bronze();

    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    const std::string getTypeInfo() const override;
};


#endif //CARRENTAL_BRONZE_H
