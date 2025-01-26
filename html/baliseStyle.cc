#include "baliseStyle.hh"

BaliseStyle::BaliseStyle(NoeudPtr contenu, NoeudPtr style)
    : NoeudElement(contenu), _style(style) {

}

std::string BaliseStyle::toHTML(const Contexte & contexte) const {
    std::string style = _style->toHTML(contexte);
    std::string text = contenu()->toHTML(contexte);
    return "\t\t<" + nomBalise() + " " + style + ">" + text + "</" + nomBalise() + ">\n";
}
