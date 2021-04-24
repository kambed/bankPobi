//
// Created by student on 24.04.2021.
//

#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H


#include "ClientType.h"

class Silver: public ClientType {
public:
    Silver();

    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    const std::string getTypeInfo() const override;
};


#endif //CARRENTAL_SILVER_H
