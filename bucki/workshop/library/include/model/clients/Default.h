#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H


#include "ClientType.h"

class Default : public ClientType {
private:
    int maxVehicles = 1;
public:
    int getMaxVehicles() const override;

    std::string getTypeInfo() override;

    double applyDiscount(double price) override;
};


#endif //CARRENTAL_DEFAULT_H
