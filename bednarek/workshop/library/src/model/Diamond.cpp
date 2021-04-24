//
// Created by student on 24.04.2021.
//

#include "model/Diamond.h"
Diamond::Diamond() {}
int Diamond::getMaxVehicles() const {
    return 10;
}

double Diamond::applyDiscount(double price) const {
    double discount;
    if(price<=125){
        discount=0.9;
    }
    else if(price>125 && price<=250){
        discount=0.8;
    }
    else if(price>250 && price<=500){
        discount=0.7;
    }
    else{
        discount=0.6;
    }
    return ClientType::applyDiscount(price)*discount;
}

const std::string Diamond::getTypeInfo() const {
    return "Diamond";
}
