#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H


#include "ClientType.h"

class Bronze : public ClientType {
private:
    int maxVehicles = 2;
    double discount = 3;
public:
    int getMaxVehicles() const override;

    std::string getTypeInfo() override;

    double applyDiscount(double in_price) override;
};


#endif //CARRENTAL_BRONZE_H
