//
// Created by student on 18.04.2021.
//

#include "repositories/VehicleRepository.h"
#include <algorithm>
VehiclePtr VehicleRepository::getVehicle(int vehicleIndex) const{
    if(Vehicles.size()>vehicleIndex){
        return Vehicles[vehicleIndex];
    }
    else{
        return nullptr;
    }
}
void VehicleRepository::addVehicle(VehiclePtr vehicle) {
    if(vehicle!=nullptr){
        Vehicles.push_back(vehicle);
    }
}
void VehicleRepository::removeVehicle(VehiclePtr vehicle) {
    if(vehicle!=nullptr){
        Vehicles.erase(std::remove(Vehicles.begin(),Vehicles.end(),vehicle));
    }
}
std::string VehicleRepository::reportVehicle() const{
    std::string rentlist=" ";
    for(int i=0;i<sizeVehicle();i++){
        rentlist=rentlist + "\n" + Vehicles[i]->getVehicleInfo();
    }
    return rentlist;
}
int VehicleRepository::sizeVehicle() const{
    return Vehicles.size();
}


