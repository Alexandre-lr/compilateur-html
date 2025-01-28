#include "propriete.hh"

Propriete::Propriete(Propriete_t type, NoeudPtr valeur)
    : _type(type), _valeur(valeur) {

}

std::string Propriete::to_html(const Contexte & contexte) const {
    std::string valeur(_valeur->to_html(contexte));

    switch (_type) {
    case Propriete_t::encodage: return "\t\t<meta charset=\"" + valeur + "\">\n";
    case Propriete_t::icone: return "\t\t<link rel=\"icon\" type=\"image/jpg\" href=\"./" + valeur + "\"/>\n";
    case Propriete_t::css: return "\t\t<link rel=\"stylesheet\" href=\"" + valeur + "\"/>\n";
    case Propriete_t::langue: return "<html lang=\"" + valeur + "\">\n";
    default: return "";
    }
}

Propriete_t const & Propriete::type() const {
    return _type;
}
