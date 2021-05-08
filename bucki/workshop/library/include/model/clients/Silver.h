#ifndef CARRENTAL_SILVER_H
#define CARRENTAL_SILVER_H


#include "ClientType.h"

class Silver : public ClientType {
private:
    int maxVehicles = 3;
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


#endif //CARRENTAL_SILVER_H
