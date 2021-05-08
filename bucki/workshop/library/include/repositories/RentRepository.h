#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H


#include <vector>
#include "typedefs.h"
#include <string>
#include <repositories/Repository.h>

class RentRepository : public Repository<Rent>{
private:
    std::vector<RentPtr> rents;
public:
    /// GETTERS

    /// \param id
    /// \return
    RentPtr getRent(unsigned int id);

    /// \return
    unsigned int getRentsSize();

    /// METHODS

    /// \param Rent
    void addRent(RentPtr Rent);

    /// \param Rent
    void removeRent(RentPtr Rent);

    /// \return
    const std::string reportRents();

    /// \param predicate
    /// \return
    std::vector<RentPtr> findBy(RentPredicate predicate);

    /// \return
    std::vector<RentPtr> findAll();
};


#endif //CARRENTAL_RENTREPOSITORY_H
