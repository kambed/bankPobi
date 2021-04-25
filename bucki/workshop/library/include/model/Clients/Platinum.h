#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H


#include "ClientType.h"

class Platinum : public ClientType {
private:
    int maxVehicles=5;
public:
    int getMaxVehicles() const override;

    std::string getTypeInfo() override;

    double applyDiscount(double price) override;
};


#endif //CARRENTAL_PLATINUM_H
