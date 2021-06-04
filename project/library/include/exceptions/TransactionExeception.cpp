#include "TransactionExeception.h"

TransactionExeception::TransactionExeception(const std::string &arg) : logic_error(arg) {}
