#ifndef CARRENTAL_PLATINUM_H
#define CARRENTAL_PLATINUM_H


#include "ClientType.h"

class Platinum : public ClientType {
private:
    int maxVehicles = 5;
public:
    /// GETTERS

    /// \return
    int getMaxVehicles() const override;

    /// \return
    std::string getTypeInfo() override;

    /// \param price
    /// \return
    double applyDiscount(double price) override;
};


#endif //CARRENTAL_PLATINUM_H
