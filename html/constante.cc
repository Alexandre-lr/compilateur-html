#include "constante.hh"

Constante::Constante(double valeur)
    : _valeur(valeur) {

}

std::string Constante::to_html(const Contexte & contexte) const {
    return std::to_string(_valeur);
}

double Constante::valeur() const {
    return _valeur;
}
