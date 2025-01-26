#include "noeudElement.hh"

NoeudElement::NoeudElement(const NoeudPtr & contenu)
    : _contenu(contenu) {

}

NoeudPtr NoeudElement::contenu() const {
    return _contenu;
}
