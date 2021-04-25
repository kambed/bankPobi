#include <string>

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H


class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented=false;
public:
    Vehicle(const std::string &plateNumber, const unsigned int basePrice);

    virtual ~Vehicle();

    const std::string &getPlateNumber() const;

    void setPlateNumber(const std::string &plateNumber);

    const unsigned int getBasePrice() const;

    void setBasePrice(const unsigned int basePrice);

    virtual const std::string getVehicleInfo() const;

    bool isRented() const;

    void setRented(bool rented);

    virtual double getActualRentalPrice();
};


#endif //CARRENTAL_VEHICLE_H