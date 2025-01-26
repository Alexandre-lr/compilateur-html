#include "baliseParagrahpe.hh"

BaliseParagraphe::BaliseParagraphe(NoeudPtr text, NoeudPtr style)
    : BaliseStyle(text, style) {

}

std::string BaliseParagraphe::nomBalise() const {
    return "p";
}
