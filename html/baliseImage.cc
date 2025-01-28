#include "baliseImage.hh"

BaliseImage::BaliseImage(NoeudPtr src)
    : NoeudElement(src) {

}

std::string BaliseImage::to_html(const Contexte & contexte) const {
    return "\t\t<" + nom_balise() + " src=" + contenu()->to_html(contexte) + "\">\n";
}

std::string BaliseImage::nom_balise() const {
    return "img";
}
