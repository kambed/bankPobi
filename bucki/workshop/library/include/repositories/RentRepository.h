#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H


#include <vector>
#include "typedefs.h"
#include <string>

class RentRepository {
private:
    std::vector<RentPtr> rents;
public:

    RentPtr getRent(unsigned int id) const;

    void addRent(RentPtr Rent);

    void removeRent(RentPtr Rent);

    const std::string reportRents() const;

    unsigned int getRentsSize();

//    std::vector<RentPtr> findBy(RentPredicate predicate) const;
//
//    std::vector<RentPtr> findAll() const;
};


#endif //CARRENTAL_RENTREPOSITORY_H
