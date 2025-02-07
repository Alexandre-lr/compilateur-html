#include "baliseParagraphe.hh"

BaliseParagraphe::BaliseParagraphe(NoeudPtr text, NoeudPtr style)
    : BaliseStyle(text, style) {

}

std::string BaliseParagraphe::nom_balise() const {
    return "p";
}
