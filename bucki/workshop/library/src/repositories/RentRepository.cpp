#include <algorithm>
#include "repositories/RentRepository.h"
#include "model/Rent.h"
#include "typedefs.h"

RentPtr RentRepository::getRent(unsigned int id) const{
    if(rents.size()-1<id)
        return nullptr;
    if(rents.at(id) == nullptr)
        return nullptr;
    return rents.at(id);
}

void RentRepository::addRent(RentPtr rent){
    if(rent != nullptr)
        rents.push_back(rent);
}

void RentRepository::removeRent(RentPtr rent){
    if(rent != nullptr)
        rents.erase(std::remove(rents.begin(), rents.end(), rent));
}

const std::string RentRepository::reportRents() const{
    std::string report="";
    for(int i=0;i<rents.size();i++)
        report += rents[i]->getRentInfo()+"\n";
    return report;
}

unsigned int RentRepository::getRentsSize(){
    return rents.size();
}

std::vector<RentPtr> RentRepository::findBy(RentPredicate predicate) const {
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < rents.size(); i++) {
        RentPtr rent = getRent(i);
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}

bool predicateTrue(RentPtr rent){
    return rent != nullptr;
}

std::vector<RentPtr> RentRepository::findAll() const{
    return RentRepository::findBy(predicateTrue);
}