//
// Created by student on 04.05.2021.
//

#include "functors/IdPredicate.h"
IdPredicate::IdPredicate(boost::uuids::uuid id) : id(id) {}
bool IdPredicate::operator()(const RentPtr &ptr) const{
    return ptr->getId() == id;
}
