//
// Created by student on 05.04.2021.
//

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H


class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool rented=false;
public:
    Vehicle(const std::string &plateNumber, unsigned int basePrice);

    const std::string &getPlateNumber() const;

    void setPlateNumber(const std::string &plateNumber);

    unsigned int getBasePrice() const;

    void setBasePrice(unsigned int basePrice);

    const std::string getVehicleInfo() const;

    bool isRented() const;

    void setRented(bool rented);
};


#endif //CARRENTAL_VEHICLE_H
