#ifndef CARRENTAL_DIAMOND_H
#define CARRENTAL_DIAMOND_H


#include "ClientType.h"

class Diamond : public ClientType {
private:
    int maxVehicles = 10;
public:
    /// GETTERS

    /// \return
    int getMaxVehicles() const override;

    /// \return
    std::string getTypeInfo() override;

    /// METHODS

    /// \param price
    /// \return
    double applyDiscount(double price) override;
};


#endif //CARRENTAL_DIAMOND_H
