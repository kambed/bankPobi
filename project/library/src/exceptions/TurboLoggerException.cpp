#include "exceptions/TurboLoggerException.h"

TurboLoggerException::TurboLoggerException(const std::string &arg) : logic_error(arg) {}
