#include "attribut.hh"

Attribut::Attribut(Attribut_t type, NoeudPtr valeur)
    : _type(type), _valeur(valeur) {

}

std::string Attribut::toHTML(const Contexte & contexte) const {
    std::string valeur = _valeur->toHTML(contexte);
    switch (_type) {
        case Attribut_t::largeur: return "width:" + valeur + ";";
        case Attribut_t::hauteur: return "height:" + valeur + ";";
        case Attribut_t::couleurTexte: return "color:" + valeur + ";";
        case Attribut_t::couleurFond: return "background-color:" + valeur + ";";
        case Attribut_t::opacite: return "opacity:" + valeur + ";";
        default: return "";
    }
}

Attribut_t const & Attribut::type() const {
    return _type;
}
