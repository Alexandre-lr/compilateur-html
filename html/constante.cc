#include "constante.hh"

Constante::Constante(int valeur)
    : _valeur(valeur) {

}

std::string Constante::to_html(const Contexte & contexte) const {
    return std::to_string(_valeur);
}

int Constante::valeur() const {
    return _valeur;
}
