#include "model/Clients/ClientType.h"

double ClientType::applyDiscount(double price) {
    return price * 1.00;
}

std::string ClientType::getTypeInfo() {
    return "Maksymalna liczba wyporzyczonych pojazdow: " + std::to_string(getMaxVehicles()) + "Upust: ";
}

int ClientType::getMaxVehicles() const {
    return maxVehicles;
}
