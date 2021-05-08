#ifndef CARRENTAL_GOLD_H
#define CARRENTAL_GOLD_H


#include "ClientType.h"

class Gold : public ClientType {
private:
    int maxVehicles = 4;
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


#endif //CARRENTAL_GOLD_H
