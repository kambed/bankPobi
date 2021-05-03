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
    bool archive=false;
public:
    //CONSTRUCTOR
    Vehicle(const std::string &plateNumber, unsigned int basePrice);
    //DESTRUCTOR
    virtual ~Vehicle()=0;

    //GETTERS
    const std::string &getId() const;
    const std::string &getPlateNumber() const;
    unsigned int getBasePrice() const;
    bool isArchive() const;
    virtual const std::string getInfo() const;
    virtual const std::string getVehicleInfo() const;

    //SETTERS
    void setPlateNumber(const std::string &plateNumber);
    void setBasePrice(unsigned int basePrice);
    void setArchive(bool archive);
    virtual double getActualRentalPrice();
};


#endif //CARRENTAL_VEHICLE_H
