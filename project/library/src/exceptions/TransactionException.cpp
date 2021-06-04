#include "exceptions/TransactionException.h"

TransactionException::TransactionException(const std::string &arg) : logic_error(arg) {}
