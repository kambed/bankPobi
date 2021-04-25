#include "model/Clients/Silver.h"

int Silver::getMaxVehicles() const {
    return maxVehicles;
}

std::string Silver::getTypeInfo() {
    return "Silver: " + ClientType::getTypeInfo() + "6";
}

double Silver::applyDiscount(double price) {
    return 6;
}
