#include "noeudCorps.hh"
#include "noeudElement.hh"

std::string NoeudCorps::toHTML(const Contexte & contexte) const {
    std::string body = "\t<body>\n";
    for (auto const & element : _elements) {
        body += element->toHTML(contexte);
    }
    body += "\t</body>\n";
    return body;
}

void NoeudCorps::ajouterElement(NoeudPtr element) {
    auto e = std::dynamic_pointer_cast<NoeudElement>(element);
    _elements.push_back(std::move(e));
}
