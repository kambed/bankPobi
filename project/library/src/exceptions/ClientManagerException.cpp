#include "exceptions/ClientManagerException.h"

ClientManagerException::ClientManagerException(const std::string &arg) : logic_error(arg) {}
