#ifndef CARRENTAL_IDPREDICATE_H
#define CARRENTAL_IDPREDICATE_H


#include "../typedefs.h"
#include "../model/Rent.h"

class IdPredicate
{
private:
    boost::uuids::uuid id;

public:
    IdPredicate(boost::uuids::uuid id);

    bool operator()(const RentPtr &ptr) const;
};


#endif //CARRENTAL_IDPREDICATE_H
