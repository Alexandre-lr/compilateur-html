#include "baliseImage.hh"

BaliseImage::BaliseImage(NoeudPtr src)
    : NoeudElement(src) {

}

std::string BaliseImage::toHTML(const Contexte & contexte) const {
    return "\t\t<" + nomBalise() + " src=" + contenu()->toHTML(contexte) + "\">\n";
}

std::string BaliseImage::nomBalise() const {
    return "img";
}
