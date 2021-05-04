//
// Created by student on 04.05.2021.
//

#include <regex>
#include <boost/regex.hpp>
#include <iostream>
#include "FirstNamePredicate.h"
#include <string>

bool FirstNamePredicate::operator()(const ClientPtr &ptr) const {
    std::string test="("+firstname+")(.*)";
    return regex_match (ptr->getFirstName(), std::regex(test));
}
FirstNamePredicate::FirstNamePredicate(const std::string &firstname) : firstname(firstname) {}
