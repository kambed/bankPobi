#include "functors/IdPredicate.h"

IdPredicate::IdPredicate(boost::uuids::uuid id) : id(id) {}

bool IdPredicate::operator()(const RentPtr &ptr) const{
    return ptr->getId() == id;
}