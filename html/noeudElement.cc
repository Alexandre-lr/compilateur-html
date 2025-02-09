#include "noeudElement.hh"
#include <iostream>

NoeudElement::NoeudElement(const NoeudPtr & contenu)
    : _contenu(contenu) {

}

NoeudPtr NoeudElement::contenu() const {
    return _contenu;
}

std::string NoeudElement::tag() const {
    switch (type_balise()) {
        case Bloc_t::commentaire: return "";
        case Bloc_t::image: return "img";
        case Bloc_t::paragraphe: return "p";
        case Bloc_t::titre1: return "h1";
        case Bloc_t::titre2: return "h2";
        case Bloc_t::titre3: return "h3";
        case Bloc_t::titre4: return "h4";
        case Bloc_t::titre5: return "h5";
        case Bloc_t::titre6: return "h6";
        case Bloc_t::titre7: return "h7";
        case Bloc_t::titre8: return "h8";
        case Bloc_t::titre9: return "h9";
        default: return "";
    }
}

std::ostream& operator<<(std::ostream& os, const NoeudElement::Bloc_t& bloc) {
    switch (bloc) {
        case NoeudElement::Bloc_t::commentaire: os << "commentaire"; break;
        case NoeudElement::Bloc_t::image: os << "image"; break;
        case NoeudElement::Bloc_t::paragraphe: os << "paragraphe"; break;
        case NoeudElement::Bloc_t::titre1: os << "titre1"; break;
        case NoeudElement::Bloc_t::titre2: os << "titre2"; break;
        case NoeudElement::Bloc_t::titre3: os << "titre3"; break;
        case NoeudElement::Bloc_t::titre4: os << "titre4"; break;
        case NoeudElement::Bloc_t::titre5: os << "titre5"; break;
        case NoeudElement::Bloc_t::titre6: os << "titre6"; break;
        case NoeudElement::Bloc_t::titre7: os << "titre7"; break;
        case NoeudElement::Bloc_t::titre8: os << "titre8"; break;
        case NoeudElement::Bloc_t::titre9: os << "titre9"; break;
        default: os << ""; break;
    }
    return os;
}
