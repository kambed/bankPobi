#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H


#include <string>

class ClientType {
private:
    int maxVehicles = 1;
public:
    /// GETTERS

    /// \return
    virtual int getMaxVehicles() const;

    /// \return
    virtual std::string getTypeInfo();

    /// METHODS

    /// \param in_price
    /// \return
    virtual double applyDiscount(double in_price);
};


#endif //CARRENTAL_CLIENTTYPE_H
