#include "driver.hh"
#include <iostream>

Driver::Driver() {}
Driver::~Driver() {}


const Contexte& Driver::getContexte() const {
    return variables;
}

double Driver::getVariable(const std::string & name) const {
    return variables.get(name);
}

void Driver::setVariable(const std::string & name, double value) {
    variables[name] = value;
}

