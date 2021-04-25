//
// Created by student on 18.04.2021.
//

#include "repositories/RentRepository.h"
RentPtr RentRepository::getRent(int rentIndex) const{
    if(Rents.size()>rentIndex)
    {
        return Rents[rentIndex];
    }
    else
    {
        return nullptr;
    }
}
void RentRepository::addRent(RentPtr rent) {
    if(rent!=nullptr){
        Rents.push_back(rent);
    }
}
void RentRepository::removeRent(RentPtr rent) {
    if(rent!=nullptr){
        Rents.erase(std::remove(Rents.begin(),Rents.end(),rent));
    }
}
std::string RentRepository::reportRent() const{
    std::string rentlist=" ";
    for(int i=0;i<sizeRent();i++){
        rentlist=rentlist + "\n" + Rents[i]->getRentInfo();
    }
    return rentlist;
}
int RentRepository::sizeRent() const{
    return Rents.size();
}
std::vector<RentPtr> RentRepository::findBy(RentPredicate predicate) const {
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < Rents.size(); i++) {
        RentPtr rent = Rents[i];
        if (rent != nullptr && predicate(rent)) {
            found.push_back(rent);
        }
    }
    return found;
}
bool testTrue(RentPtr ptr)
{
    return ptr != nullptr;
}
std::vector<RentPtr> RentRepository::findAll() {
    return findBy(testTrue);
}
