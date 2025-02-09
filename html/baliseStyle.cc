#include <iostream>
#include "baliseStyle.hh"
#include "style.hh"

BaliseStyle::BaliseStyle(NoeudPtr contenu, NoeudPtr style)
    : NoeudElement(contenu), _style(style) {

}

std::string BaliseStyle::to_html(const Contexte & contexte) const {
    std::string style(_style->to_html(contexte));
    std::string texte(contenu()->to_html(contexte));

    return "\t\t<" + tag() + style + ">" + texte + "</" + tag() + ">\n";
}

NoeudPtr& BaliseStyle::style() {
    return _style;
}

NoeudPtr& BaliseStyle::attribut(Attribut::Attribut_t attribut) {
    return std::dynamic_pointer_cast<Style>(_style)->attribut(attribut);
}

void BaliseStyle::modifier_attribut(NoeudPtr attribut) {
    auto nouveauattribut(std::dynamic_pointer_cast<Attribut>(attribut));

    if (nouveauattribut)
        std::dynamic_pointer_cast<Style>(_style)->modifier_attribut(attribut);
    else
        throw std::invalid_argument("Type invalide : Noeud-Attribut attendu.");
}
