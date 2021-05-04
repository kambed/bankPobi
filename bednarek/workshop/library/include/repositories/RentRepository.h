//
// Created by student on 18.04.2021.
//

#ifndef CARRENTAL_RENTREPOSITORY_H
#define CARRENTAL_RENTREPOSITORY_H
#include "../model/Rent.h"
#include "../typedefs.h"
#include <string>
#include "repositories/Repository.h"
#include "functors/IdPredicate.h"

class RentRepository : public Repository<Rent>{
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
    template<class P> std::vector<RentPtr> findAllNew(const P &predicate) const
    {
        std::vector<RentPtr> result;
        for(int i = 0; i<Rents.size(); ++i)
        {
            RentPtr rent = Rents[i];
            if(predicate(rent))
            {
                result.push_back(rent);
            }
        }
        return result;
    }
};


#endif //CARRENTAL_RENTREPOSITORY_H
