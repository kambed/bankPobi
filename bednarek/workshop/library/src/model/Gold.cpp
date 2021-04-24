//
// Created by student on 24.04.2021.
//

#include "model/Gold.h"
Gold::Gold() {}
int Gold::getMaxVehicles() const {
    return 4;
}
double Gold::applyDiscount(double price) const {
    return ClientType::applyDiscount(price)*0.95;
}
const std::string Gold::getTypeInfo() const {
    return "Gold";
}
