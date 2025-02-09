#include "baliseImage.hh"

BaliseImage::BaliseImage(NoeudPtr src)
    : NoeudElement(src) {

}

std::string BaliseImage::to_html(const Contexte & contexte) const {
    return "\t\t<" + tag() + " src=" + contenu()->to_html(contexte) + ">\n";
}

NoeudElement::Bloc_t BaliseImage::type_balise() const {
    return NoeudElement::Bloc_t::image;
}
