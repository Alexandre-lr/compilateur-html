#include "baliseParagraphe.hh"

BaliseParagraphe::BaliseParagraphe(NoeudPtr texte, NoeudPtr style)
    : BaliseStyle(texte, style) {

}

NoeudElement::Bloc_t BaliseParagraphe::type_balise() const {
    return NoeudElement::Bloc_t::paragraphe;
}
