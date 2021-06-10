#include "exceptions/TransactionManagerException.h"

TransactionManagerException::TransactionManagerException(const std::string &arg) : logic_error(arg) {}
