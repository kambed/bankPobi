#include "exceptions/AccountManagerException.h"

AccountManagerException::AccountManagerException(const std::string &arg) : logic_error(arg) {}
