#include <string>

#ifndef CARRENTAL_VEHICLE_H
#define CARRENTAL_VEHICLE_H


class Vehicle {
private:
    std::string plateNumber;
    unsigned int basePrice;
    bool archive = false;
public:
    /// CONSTRUCTOR

    /// \param plateNumber
    /// \param basePrice
    Vehicle(const std::string &plateNumber, const unsigned int basePrice);

    /// DESTRUCTOR

    virtual ~Vehicle();

    ///GETTERS

    /// \return
    const std::string &getPlateNumber() const;

    /// \return
    const std::string getInfo() const;

    /// \return
    const std::string getId() const;

    /// \return
    const unsigned int getBasePrice() const;

    /// \return
    virtual const std::string getVehicleInfo() const;

    /// \return
    virtual double getActualRentalPrice();

    /// SETTERS

    /// \param basePrice
    void setBasePrice(const unsigned int basePrice);

    /// METHODS

    /// \return
    bool isArchive() const;

    /// \param archive
    void setArchive(bool archive);
};


#endif //CARRENTAL_VEHICLE_H
