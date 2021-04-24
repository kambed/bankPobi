//
// Created by student on 24.04.2021.
//

#include "model/Silver.h"
Silver::Silver() {}
int Silver::getMaxVehicles() const {
    return 3;
}

double Silver::applyDiscount(double price) const {
    return ClientType::applyDiscount(price)-6;
}

const std::string Silver::getTypeInfo() const {
    return "Silver";
}
