#include "model/Clients/Diamond.h"

int Diamond::getMaxVehicles() const {
    return maxVehicles;
}

std::string Diamond::getTypeInfo() {
    return "Diamond: " + ClientType::getTypeInfo() + "10-40%";
}

double Diamond::applyDiscount(double price) {
    if(0<=price && price<=125)
     return ClientType::applyDiscount(price)*0.1;
    else if(price<=250)
     return ClientType::applyDiscount(price)*0.2;
    else if(price<=500)
     return ClientType::applyDiscount(price)*0.3;
    else
     return ClientType::applyDiscount(price)*0.4;
}
