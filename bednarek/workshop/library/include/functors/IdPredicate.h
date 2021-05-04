//
// Created by student on 04.05.2021.
//

#ifndef CARRENTAL_IDPREDICATE_H
#define CARRENTAL_IDPREDICATE_H

#include <typedefs.h>
#include <boost/uuid/uuid.hpp>
#include "model/Rent.h"

class IdPredicate {
private:
    boost::uuids::uuid id;
public:
    IdPredicate(boost::uuids::uuid id);
    bool operator()(const RentPtr &ptr) const;
};


#endif //CARRENTAL_IDPREDICATE_H
