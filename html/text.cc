#include "text.hh"

Text::Text(std::string const & valeur) : _valeur(valeur) {}

std::string Text::to_html(const Contexte & contexte) const {
    return _valeur;
}
