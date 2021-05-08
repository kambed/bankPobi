#ifndef CARRENTAL_RENTEXCEPTION_H
#define CARRENTAL_RENTEXCEPTION_H

#include <stdexcept>

class RentException : public std::logic_error {
public:
    /// \param arg
    explicit RentException(const std::string &arg);
};


#endif //CARRENTAL_RENTEXCEPTION_H
