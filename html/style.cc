#include "style.hh"
#include <iostream>
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

NoeudPtr& Style::attribut(Attribut_t type) {
    return _attributs[type];
}

Style& Style::operator=(const Style& s) {
    if (this != &s)
        _attributs = s._attributs;

    return *this;
}

void Style::modifier_attribut(NoeudPtr attribut) {
    auto atype(std::dynamic_pointer_cast<Attribut>(attribut)->type());

    auto it(_attributs.find(atype));
    if (it != _attributs.end())
        it->second = attribut;
    else
        _attributs[atype] = attribut;
}
