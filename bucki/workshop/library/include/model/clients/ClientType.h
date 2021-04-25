#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H


#include <string>

class ClientType {
private:
    int maxVehicles = 1;
public:
    virtual int getMaxVehicles() const;

    virtual std::string getTypeInfo();

    virtual double applyDiscount(double in_price);
};


#endif //CARRENTAL_CLIENTTYPE_H
