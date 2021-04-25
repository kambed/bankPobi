#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H


#include "ClientType.h"

class Diamond : public ClientType{
private:
    int maxVehicles=10;
public:
    int getMaxVehicles() const override;

    std::string getTypeInfo() override;

    double applyDiscount(double price) override;
};


#endif //CARRENTAL_DIAMOND_H
