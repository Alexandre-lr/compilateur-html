#include "noeudCorps.hh"
#include "noeudElement.hh"
#include <iostream>

std::string NoeudCorps::to_html(const Contexte & contexte) const {
    std::string body("\t<body>\n");
    for (auto const & element : _elements) {
        body += element->to_html(contexte);
    }
    body += "\t</body>\n";

    return body;
}

NoeudPtr& NoeudCorps::element(const std::size_t & idx, const std::string & balise) {
    auto i(0);
    for (auto & e : _elements) {
        auto p(std::dynamic_pointer_cast<NoeudElement>(e));
        if (p && (p->nom_balise() == balise)) {
            if (i == idx)
                return e;
            else
                i++;
        }
    }
    throw std::out_of_range("Élément introuvable pour l'index et la balise donnés.");
}

void NoeudCorps::ajouter_element(NoeudPtr element) {
    auto e(std::dynamic_pointer_cast<NoeudElement>(element));
    _elements.push_back(std::move(e));
}
