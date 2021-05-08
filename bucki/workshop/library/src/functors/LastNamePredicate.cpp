#include <typedefs.h>
#include <regex>
#include "functors/LastNamePredicate.h"
#include "model/clients/Client.h"

LastNamePredicate::LastNamePredicate(const std::string &lastname) : lastname(lastname) {}

bool LastNamePredicate::operator()(const ClientPtr &ptr) const {
    std::string lastNameTemplate = "("+lastname+")(.*)";
    return regex_match (ptr->getLastName(), std::regex(lastNameTemplate));
}