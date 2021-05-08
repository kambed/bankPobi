#ifndef CARRENTAL_IDPREDICATE_H
#define CARRENTAL_IDPREDICATE_H


#include "../typedefs.h"
#include "../model/Rent.h"

class IdPredicate
{
private:
    boost::uuids::uuid id;
public:

    /// \param id
    IdPredicate(boost::uuids::uuid id);

    /// \param ptr
    /// \return
    bool operator()(const RentPtr &ptr) const;
};


#endif //CARRENTAL_IDPREDICATE_H
