#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H


#include "ClientType.h"

class Silver : public ClientType {
private:
    int maxVehicles = 3;
public:
    int getMaxVehicles() const override;

    std::string getTypeInfo() override;

    double applyDiscount(double in_price) override;
};


#endif //CARRENTAL_SILVER_H
