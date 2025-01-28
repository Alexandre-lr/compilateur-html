#include "baliseStyle.hh"
#include "style.hh"

BaliseStyle::BaliseStyle(NoeudPtr contenu, NoeudPtr style)
    : NoeudElement(contenu), _style(style) {

}

std::string BaliseStyle::to_html(const Contexte & contexte) const {
    std::string style(_style->to_html(contexte));
    std::string text(contenu()->to_html(contexte));

    return "\t\t<" + nom_balise() + style + ">" + text + "</" + nom_balise() + ">\n";
}

NoeudPtr& BaliseStyle::style() {
    return _style;
}

NoeudPtr& BaliseStyle::attribut(Attribut_t attribut) {
    return std::dynamic_pointer_cast<Style>(_style)->attribut(attribut);
}

void BaliseStyle::modifier_attribut(NoeudPtr attribut) {
    std::dynamic_pointer_cast<Style>(_style)->modifier_attribut(attribut);
}
