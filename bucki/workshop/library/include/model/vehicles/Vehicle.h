#include <string>

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H


class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool archive = false;
public:
    Vehicle(const std::string &plateNumber, const unsigned int basePrice);

    virtual ~Vehicle();

    const std::string &getPlateNumber() const;

    //void setPlateNumber(const std::string &plateNumber);

    const unsigned int getBasePrice() const;

    void setBasePrice(const unsigned int basePrice);

    virtual const std::string getVehicleInfo() const;

    virtual double getActualRentalPrice();

    bool isArchive() const;

    void setArchive(bool archive);
};


#endif //CARRENTAL_VEHICLE_H
