#include "texte.hh"
#include <iostream>
#include <regex>

Texte::Texte(std::string const & valeur) : _valeur(valeur) {}

std::string Texte::to_html(const Contexte & contexte) const {
    return std::regex_replace(_valeur, std::regex(R"(\\')"), "'");
}

// Meme definition que to_html mais utilisé pour un contexte different
std::string& Texte::valeur() {
    return _valeur;
}
