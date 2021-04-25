#include "model/Clients/Default.h"

int Default::getMaxVehicles() const {
    return maxVehicles;
}

std::string Default::getTypeInfo() {
    return "Default: " + ClientType::getTypeInfo() + "0";
}

double Default::applyDiscount(double price) {
    return 0;
}
