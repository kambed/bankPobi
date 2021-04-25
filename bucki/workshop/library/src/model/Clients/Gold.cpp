#include "model/Clients/Gold.h"

int Gold::getMaxVehicles() const {
    return maxVehicles;
}

std::string Gold::getTypeInfo() {
    return "Gold: " + ClientType::getTypeInfo() + "5%";
}

double Gold::applyDiscount(double price) {
    return ClientType::applyDiscount(price)*0.05;
}
