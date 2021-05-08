#ifndef CARRENTAL_DEFAULT_H
#define CARRENTAL_DEFAULT_H


#include "ClientType.h"

class Default : public ClientType {
private:
    int maxVehicles = 1;
public:
    /// GETTERS

    /// \return
    int getMaxVehicles() const override;

    /// \return
    std::string getTypeInfo() override;

    ///METHODS

    /// \param price
    /// \return
    double applyDiscount(double price) override;
};


#endif //CARRENTAL_DEFAULT_H
