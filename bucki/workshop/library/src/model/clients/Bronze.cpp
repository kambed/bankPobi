#include "model/Clients/Bronze.h"

int Bronze::getMaxVehicles() const {
    return maxVehicles;
}

std::string Bronze::getTypeInfo() {
    return "Bronze: " + ClientType::getTypeInfo() + "3";
}

double Bronze::applyDiscount(double price) {
    return 3;
}
