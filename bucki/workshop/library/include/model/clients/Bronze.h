#ifndef CARRENTAL_BRONZE_H
#define CARRENTAL_BRONZE_H


#include "ClientType.h"

class Bronze : public ClientType {
private:
    int maxVehicles = 2;
    double discount = 3;
public:
    /// GETTERS

    /// \return
    int getMaxVehicles() const override;

    /// \return
    std::string getTypeInfo() override;

    /// METHODS

    /// \param in_price
    /// \return
    double applyDiscount(double in_price) override;
};


#endif //CARRENTAL_BRONZE_H
