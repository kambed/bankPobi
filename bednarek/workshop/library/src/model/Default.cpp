//
// Created by student on 24.04.2021.
//

#include "model/Default.h"
Default::Default() {}

int Default::getMaxVehicles() const {
    return 1;
}
double Default::applyDiscount(double price) const {
    return ClientType::applyDiscount(price);
}
const std::string Default::getTypeInfo() const {
    return "Default";
}
