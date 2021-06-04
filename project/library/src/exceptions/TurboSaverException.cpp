//
// Created by student on 04.06.2021.
//

#include "exceptions/TurboSaverException.h"

TurboSaverException::TurboSaverException(const std::string &arg) : logic_error(arg) {}
