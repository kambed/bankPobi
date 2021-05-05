#include "model/Clients/ClientType.h"

double ClientType::applyDiscount(double price) {
    return 0;
}

std::string ClientType::getTypeInfo() {
    return "Maksymalna liczba wyporzyczonych pojazdow: " + std::to_string(getMaxVehicles()) + ", Upust: ";
}

int ClientType::getMaxVehicles() const {
    return maxVehicles;
}
