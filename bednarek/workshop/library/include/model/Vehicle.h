//
// Created by student on 05.04.2021.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H
#include <string>

class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented=false;
public:
    //CONSTRUCTOR
    Vehicle(const std::string &plateNumber, unsigned int basePrice);
    //DESTRUCTOR
    virtual ~Vehicle()=0;

    //GETTERS
    const std::string &getPlateNumber() const;
    unsigned int getBasePrice() const;

    virtual const std::string getVehicleInfo() const;
    bool isRented() const;

    //SETTERS
    void setPlateNumber(const std::string &plateNumber);
    void setBasePrice(unsigned int basePrice);
    void setRented(bool rented);

    virtual double getActualRentalPrice();
};


#endif //CARRENTAL_VEHICLE_H
