//
// Created by student on 24.04.2021.
//

#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H


#include "ClientType.h"

class Diamond: public ClientType {
public:
    Diamond();

    int getMaxVehicles() const override;
    double applyDiscount(double price) const override;
    const std::string getTypeInfo() const override;
};


#endif //CARRENTAL_DIAMOND_H
