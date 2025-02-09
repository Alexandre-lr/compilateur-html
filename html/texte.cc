#include "texte.hh"

Texte::Texte(std::string const & valeur) : _valeur(valeur) {}

std::string Texte::to_html(const Contexte & contexte) const {
    return _valeur;
}

// Meme definition que to_html mais utilisé pour un contexte different
std::string& Texte::valeur() {
    return _valeur;
}
