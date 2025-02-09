#include "baliseTitre.hh"
#include <iostream>

BaliseTitre::BaliseTitre(NoeudPtr texte, NoeudPtr style, const std::uint8_t & niveau)
    : BaliseStyle(texte, style), _niveau(niveau) {

}

NoeudElement::Bloc_t BaliseTitre::type_balise() const {
    switch (_niveau) {
        case 1: return NoeudElement::Bloc_t::titre1;
        case 2: return NoeudElement::Bloc_t::titre2;
        case 3: return NoeudElement::Bloc_t::titre3;
        case 4: return NoeudElement::Bloc_t::titre4;
        case 5: return NoeudElement::Bloc_t::titre5;
        case 6: return NoeudElement::Bloc_t::titre6;
        case 7: return NoeudElement::Bloc_t::titre7;
        case 8: return NoeudElement::Bloc_t::titre8;
        case 9: return NoeudElement::Bloc_t::titre9;
        default: throw std::invalid_argument("Niveau de titre invalide : " + std::to_string(_niveau));
    }
}
