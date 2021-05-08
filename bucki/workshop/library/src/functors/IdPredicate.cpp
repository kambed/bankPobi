#include "functors/IdPredicate.h"
bool IdPredicate::operator()(const RentPtr &ptr) const{
    return ptr->getId() == id;
}