#include "driver.hh"
#include <iostream>

Driver::Driver() {}
Driver::~Driver() {}


const Contexte& Driver::getContexte() const {
    return variables;
}

NoeudPtr& Driver::getVariable(const std::string & name) {
    return variables.get(name);
}

void Driver::setVariable(const std::string & name, NoeudPtr& value) {
    variables[name] = value;
}

