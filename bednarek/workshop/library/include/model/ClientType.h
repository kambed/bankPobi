//
// Created by student on 24.04.2021.
//

#ifndef CARRENTAL_CLIENTTYPE_H
#define CARRENTAL_CLIENTTYPE_H
#include <string>

class ClientType {
public:
    virtual int getMaxVehicles() const;
    virtual double applyDiscount(double price) const;
    virtual const std::string getTypeInfo() const;
};


#endif //CARRENTAL_CLIENTTYPE_H
