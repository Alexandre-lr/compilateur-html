#include "style.hh"
#include <iostream>
std::string Style::toHTML(const Contexte & contexte) const {
    std::string style = "";
    if (!_attributs.empty()) {
        style += "style=\"";
        for (auto const & attribut : _attributs) {
            style += attribut.second->toHTML(contexte);
        }
        style += "\"";
    }
    return style;
}

void Style::ajouterStyle(NoeudPtr attribut) {
    auto a = std::dynamic_pointer_cast<Attribut>(attribut);
    auto it = _attributs.find(a->type());
    if (it != _attributs.end()) {
        it->second = attribut;
    }
    else {
        _attributs[a->type()] = attribut;

    }
}
