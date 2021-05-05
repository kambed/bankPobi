#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H


#include <vector>
#include "typedefs.h"
#include <string>

class RentRepository {
private:
    std::vector<RentPtr> rents;
public:

    RentPtr getRent(unsigned int id);

    void addRent(RentPtr Rent);

    void removeRent(RentPtr Rent);

    const std::string reportRents();

    unsigned int getRentsSize();

    std::vector<RentPtr> findBy(RentPredicate predicate);

    std::vector<RentPtr> findAll();
};


#endif //CARRENTAL_RENTREPOSITORY_H
