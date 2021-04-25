//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include "../model/Rent.h"
#include "../typedefs.h"
#include <string>

class RentRepository {
private:
    std::vector<RentPtr> Rents;
public:
    RentPtr getRent(int rentIndex) const;
    void addRent(RentPtr rent);
    void removeRent(RentPtr rent);
    std::string reportRent() const;
    int sizeRent() const;
    std::vector<RentPtr> findBy(RentPredicate predicate) const;
    std::vector<RentPtr> findAll();
};


#endif //CARRENTAL_RENTREPOSITORY_H
