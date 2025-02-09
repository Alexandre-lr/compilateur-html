#include "style.hh"
#include <iostream>

Style::Style() {};

Style::Style(NoeudElement::Bloc_t cible)
    : _cible(cible) {}

std::string Style::to_html(const Contexte & contexte) const {
    std::string style("");

    if (!_attributs.empty()) {
        style += " style=\"";
        for (auto const & attribut : _attributs) {
            style += attribut.second->to_html(contexte);
        }
        style += "\"";
    }

    return style;
}

NoeudPtr& Style::attribut(Attribut::Attribut_t type) {
    return _attributs[type];
}

NoeudElement::Bloc_t Style::cible() const {
    return _cible;
}
Style& Style::operator=(const Style& s) {
    if (this != &s)
        _attributs = s._attributs;

    return *this;
}

void Style::modifier_attribut(NoeudPtr attribut) {
    auto nouveauattribut(std::dynamic_pointer_cast<Attribut>(attribut));
    if (nouveauattribut) {
        auto attributtype(std::dynamic_pointer_cast<Attribut>(attribut)->type_attribut());

        auto it(_attributs.find(attributtype));
        if (it != _attributs.end())
            it->second = attribut;
        else
            _attributs[attributtype] = attribut;
    }
    else
        throw std::invalid_argument("Type invalide : Noeud-Attribut attendu.");
}
