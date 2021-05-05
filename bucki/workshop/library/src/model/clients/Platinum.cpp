#include "model/Clients/Platinum.h"

int Platinum::getMaxVehicles() const {
    return maxVehicles;
}

std::string Platinum::getTypeInfo() {
    return "Platinum: " + ClientType::getTypeInfo() + "10%";
}

double Platinum::applyDiscount(double price) {
    return price * 0.1;
}
