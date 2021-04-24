//
// Created by student on 24.04.2021.
//

#include "model/Platinum.h"
Platinum::Platinum() {}
int Platinum::getMaxVehicles() const {
    return 5;
}
double Platinum::applyDiscount(double price) const {
    return ClientType::applyDiscount(price)*0.9;
}
const std::string Platinum::getTypeInfo() const {
    return "Platinum";
}
