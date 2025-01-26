#include "contexte.hh"

NoeudPtr& Contexte::get(const std::string & nom) {
    return variables[nom];
}

const NoeudPtr& Contexte::get(const std::string & nom) const {
    return variables.at(nom);
}

NoeudPtr& Contexte::operator[](const std::string & nom) {
    return variables[nom];
}

const NoeudPtr& Contexte::operator[](const std::string & nom) const {
    return variables.at(nom);
}
