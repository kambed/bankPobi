#ifndef CARRENTAL_FIRSTNAMEPREDICATE_H
#define CARRENTAL_FIRSTNAMEPREDICATE_H


#include <string>
#include <typedefs.h>

class FirstNamePredicate {
private:
    std::string firstname;
public:
    /// \param firstname
    FirstNamePredicate(const std::string &firstname);

    /// \param ptr
    /// \return
    bool operator()(const ClientPtr &ptr) const;
};



#endif //CARRENTAL_FIRSTNAMEPREDICATE_H
