#ifndef CARRENTAL_FIRSTNAMEPREDICATE_H
#define CARRENTAL_FIRSTNAMEPREDICATE_H


#include <string>
#include <typedefs.h>

class FirstNamePredicate {
private:
    std::string firstname;
public:
    FirstNamePredicate(const std::string &firstname);
    bool operator()(const ClientPtr &ptr) const;
};



#endif //CARRENTAL_FIRSTNAMEPREDICATE_H
