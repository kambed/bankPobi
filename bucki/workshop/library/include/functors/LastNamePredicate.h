#ifndef CARRENTAL_LASTNAMEPREDICATE_H
#define CARRENTAL_LASTNAMEPREDICATE_H


class LastNamePredicate {
private:
    std::string lastname;
public:

    /// \param lastname
    LastNamePredicate(const std::string &lastname);

    /// \param ptr
    /// \return
    bool operator()(const ClientPtr &ptr) const;
};


#endif //CARRENTAL_LASTNAMEPREDICATE_H
