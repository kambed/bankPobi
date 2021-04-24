//
// Created by student on 24.04.2021.
//

#include "model/Bronze.h"
Bronze::Bronze() {}
int Bronze::getMaxVehicles() const {
    return 2;
}
double Bronze::applyDiscount(double price) const {
    return ClientType::applyDiscount(price)-3;
}
const std::string Bronze::getTypeInfo() const {
    return "Bronze";
}