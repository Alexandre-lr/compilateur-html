#include "text.hh"

Text::Text(std::string const & valeur) : _valeur(valeur) {}

std::string Text::toHTML(const Contexte & contexte) const {
    return _valeur;
}
