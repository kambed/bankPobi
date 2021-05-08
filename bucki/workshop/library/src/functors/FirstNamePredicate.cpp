#include <regex>
#include "functors/FirstNamePredicate.h"
#include "model/clients/Client.h"

FirstNamePredicate::FirstNamePredicate(const std::string &firstname) : firstname(firstname) {}

bool FirstNamePredicate::operator()(const ClientPtr &ptr) const {
    std::string firstNameTemplate = "(" + firstname + ")(.*)";
    return regex_match(ptr->getFirstName(), std::regex(firstNameTemplate));
}