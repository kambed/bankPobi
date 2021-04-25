#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H


#include "ClientType.h"

class Gold : public ClientType {
private:
    int maxVehicles = 4;
public:
    int getMaxVehicles() const override;

    std::string getTypeInfo() override;

    double applyDiscount(double price) override;
};


#endif //CARRENTAL_GOLD_H
