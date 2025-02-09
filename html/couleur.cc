#include "couleur.hh"
#include "texte.hh"
#include "constante.hh"

Couleur::Couleur(NoeudPtr r, NoeudPtr v, NoeudPtr b)
    : _r(std::dynamic_pointer_cast<Constante>(r)->valeur()), _v(std::dynamic_pointer_cast<Constante>(v)->valeur()), _b(std::dynamic_pointer_cast<Constante>(b)->valeur()) {

}

Couleur::Couleur(NoeudPtr couleurHex) {
    auto couleur(std::dynamic_pointer_cast<Texte>(couleurHex)->valeur());
    _r = static_cast<std::uint8_t>(std::stoi(couleur.substr(1, 2), nullptr, 16));
    _v = static_cast<std::uint8_t>(std::stoi(couleur.substr(3, 2), nullptr, 16));
    _b = static_cast<std::uint8_t>(std::stoi(couleur.substr(5, 2), nullptr, 16));
}

std::string Couleur::to_html(const Contexte & contexte) const {
    std::stringstream ss;
    ss << "#"
       << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(_r)
       << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(_v)
       << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(_b);

    return ss.str();
}
