//
// Created by student on 04.05.2021.
//

#include "LastNamePredicate.h"
#include <regex>
#include <boost/regex.hpp>
#include <iostream>
#include "FirstNamePredicate.h"
#include <string>

bool LastNamePredicate::operator()(const ClientPtr &ptr) const {
    std::string test="("+lastname+")(.*)";
    return regex_match (ptr->getLastName(), std::regex(test));
}
LastNamePredicate::LastNamePredicate(const std::string &lastname) : lastname(lastname) {}

