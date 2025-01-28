#include <iostream>
#include "noeudCorps.hh"
#include "noeudElement.hh"
#include "baliseStyle.hh"
#include "text.hh"
#include "baliseCommentaire.hh"
#include "style.hh"

std::string NoeudCorps::to_html(const Contexte & contexte) const {
    if (!_fini)
        finaliser_html(contexte);

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

void NoeudCorps::ajouter_attribut(NoeudPtr attribut, std::string type) {
    auto it(_styles.find(type));
    if (it == _styles.end()) {
        _styles[type] = std::make_shared<Style>();
        it = _styles.find(type);
    }
    std::dynamic_pointer_cast<Style>(it->second)->modifier_attribut(attribut);
}

void NoeudCorps::regrouper_commentaires(const Contexte & contexte) const {
    std::string text("");
    bool contientcommentaire(false);

    auto it = _elements.begin();
    while (it != _elements.end()) {
        auto commentaire(std::dynamic_pointer_cast<BaliseCommentaire>(*it));
        if (commentaire) {
            contientcommentaire = true;
            text += "\n" + commentaire->contenu()->to_html(contexte);
            it = _elements.erase(it);
        } else {
            ++it;
        }
    }
    text += "\n";
    if (contientcommentaire)
        _elements.insert(_elements.begin(), std::make_shared<BaliseCommentaire>(std::make_shared<Text>(text)));
}

void NoeudCorps::appliquer_styles() const {
    for (auto const & element : _elements) {
        auto elementstyle(std::dynamic_pointer_cast<BaliseStyle>(element));
        if (elementstyle && (_styles.find(elementstyle->nom_balise()) != _styles.end()))
            elementstyle->style() = _styles.at(elementstyle->nom_balise());
    }
}

void NoeudCorps::finaliser_html(const Contexte & contexte) const {
    regrouper_commentaires(contexte);
    appliquer_styles();
    _fini = true;
}
