//
// Created by student on 24.04.2021.
//

#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H


#include "ClientType.h"

class Gold: public ClientType {
public:
    Gold();

    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    const std::string getTypeInfo() const override;
};


#endif //CARRENTAL_GOLD_H
