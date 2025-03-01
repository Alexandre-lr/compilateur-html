#include "attribut.hh"

Attribut::Attribut(Attribut_t type, NoeudPtr valeur)
    : _type(type), _valeur(valeur) {

}

std::string Attribut::to_html(const Contexte & contexte) const {
    std::string valeur(_valeur->to_html(contexte));

    switch (_type) {
        case Attribut_t::largeur: return "width:" + valeur + ";";
        case Attribut_t::hauteur: return "height:" + valeur + ";";
        case Attribut_t::couleurTexte: return "color:" + valeur + ";";
        case Attribut_t::couleurFond: return "background-color:" + valeur + ";";
        case Attribut_t::opacite: return "opacity:" + valeur + ";";
        default: return "";
    }
}

Attribut& Attribut::operator=(const Attribut & a) {
    if (this != &a)
        if (this->_type != a._type)
            _valeur = a._valeur;

    return *this;
}

Attribut::Attribut_t const & Attribut::type_attribut() const {
    return _type;
}
