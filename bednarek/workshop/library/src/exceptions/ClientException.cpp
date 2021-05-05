//
// Created by student on 03.05.2021.
//

#include "exceptions/ClientException.h"

ClientException::ClientException(const std::string &arg) : logic_error(arg) {}
