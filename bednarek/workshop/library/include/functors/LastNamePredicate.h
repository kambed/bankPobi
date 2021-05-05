//
// Created by student on 04.05.2021.
//

#ifndef CARRENTAL_LASTNAMEPREDICATE_H
#define CARRENTAL_LASTNAMEPREDICATE_H

#include <string>
#include <typedefs.h>
#include "model/Client.h"
#include <boost/regex.hpp>
class LastNamePredicate {
private:
    std::string lastname;
public:
    LastNamePredicate(const std::string &lastname);
    bool operator()(const ClientPtr &ptr) const;
};


#endif //CARRENTAL_LASTNAMEPREDICATE_H
