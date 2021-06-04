#include "exceptions/AccountException.h"

AccountException::AccountException(const std::string &arg) : logic_error(arg) {}
