//
// Created by student on 04.05.2021.
//

#ifndef CARRENTAL_FIRSTNAMEPREDICATE_H
#define CARRENTAL_FIRSTNAMEPREDICATE_H


#include <string>
#include <typedefs.h>
#include "model/Client.h"
#include <boost/regex.hpp>

class FirstNamePredicate {
private:
    std::string firstname;
public:
    FirstNamePredicate(const std::string &firstname);
    bool operator()(const ClientPtr &ptr) const;
};


#endif //CARRENTAL_FIRSTNAMEPREDICATE_H
