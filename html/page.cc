#include <iostream>
#include "page.hh"
#include "noeudElement.hh"
#include "baliseStyle.hh"
#include "texte.hh"
#include "baliseCommentaire.hh"
#include "style.hh"
#include "propriete.hh"
#include "constante.hh"

std::string Page::to_html(const Contexte & contexte) const {
    std::string entete(_proprietes.at(Propriete::Propriete_t::langue)->to_html(contexte));
    entete += "\t<head>\n";
    for (auto const & propriete : _proprietes)
        if (propriete.first != Propriete::Propriete_t::langue)
            entete += propriete.second->to_html(contexte);
    entete += "\t\t<title>" + _titre->to_html(contexte) + "</title>\n";
    entete += "\t</head>\n";

    std::string corps("\t<body>\n");
    if (!_fini)
        finaliser_html(contexte);

    for (auto const & element : _elements)
        corps += element->to_html(contexte);
    corps += "\t</body>\n";

    std::string page("<!DOCTYPE html>\n");
    page += entete;
    page += corps;
    page += "</html>";

    return page;
}

void Page::sauvegarder(const std::string & dest, const Contexte & contexte) const {
    std::ofstream fichier(dest);

    if (fichier.is_open()) {
            fichier << this->to_html(contexte);
            fichier.close();
            std::cout << "Fichier sauvegardé avec succès : " << dest << std::endl;
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier " << dest << " !" << std::endl;
        }
}

NoeudPtr& Page::element(NoeudPtr idx, NoeudElement::Bloc_t type) {
    auto indice(std::dynamic_pointer_cast<Constante>(idx)->valeur());

    auto i(0);
    for (auto & element : _elements) {
        auto bloc(std::dynamic_pointer_cast<NoeudElement>(element));

        if (bloc && (bloc->type_balise() == type)) {
            if (i == indice)
                return element;
            else
                i++;
        }
    }
    throw std::out_of_range("Selecteur invalide : élément introuvable pour l'indice " + std::to_string(indice) + " et le type donné.");
}

void Page::ajouter_element(NoeudPtr element) {
    auto nouveauelement(std::dynamic_pointer_cast<NoeudElement>(element));

    if (nouveauelement)
        _elements.push_back(std::move(element));
    else
        throw std::invalid_argument("Type invalide : Noeud-Element attendu.");

}

void Page::ajouter_style(NoeudPtr style) {
    auto nouveaustyle(std::dynamic_pointer_cast<Style>(style));

    if (nouveaustyle)
        _styles[nouveaustyle->cible()] = style;
    else
        throw std::invalid_argument("Type invalide : Noeud-Style attendu.");
}

const NoeudPtr & Page::langue() const {
    return _proprietes.at(Propriete::Propriete_t::langue);
}

void Page::modifier_propriete(NoeudPtr propriete) {
    auto proprietetype(std::dynamic_pointer_cast<Propriete>(propriete)->type_propriete());

    auto it(_proprietes.find(proprietetype));
    if (it != _proprietes.end())
        it->second = propriete;
    else
        _proprietes[proprietetype] = propriete;
}

void Page::modifier_titre(NoeudPtr titre) {
    auto nouveautitre(std::dynamic_pointer_cast<Texte>(titre));

    if (nouveautitre)
        _titre = titre;
    else
        throw std::invalid_argument("Type invalide : Noeud-Texte attendu.");
}

void Page::regrouper_commentaires(const Contexte & contexte) const {
    std::string commentairestexte;
    bool contientcommentaire(false);

    auto it = _elements.begin();
    while (it != _elements.end()) {
        auto commentaire(std::dynamic_pointer_cast<BaliseCommentaire>(*it));

        if (commentaire) {
            contientcommentaire = true;
            commentairestexte += "\n" + commentaire->contenu()->to_html(contexte);

            it = _elements.erase(it);
        } else
            ++it;
    }

    commentairestexte += "\n";

    if (contientcommentaire)
        _elements.insert(_elements.begin(), std::make_shared<BaliseCommentaire>(std::make_shared<Texte>(commentairestexte)));
}

void Page::appliquer_styles() const {
    auto stylepage = _styles.find(NoeudElement::Bloc_t::page);
    if (stylepage != _styles.end()) {
        NoeudPtr nouveaustyle = stylepage->second;

        for (auto &element : _elements) {
            auto elementstyle = std::dynamic_pointer_cast<BaliseStyle>(element);

            if (elementstyle) {
                elementstyle->style() = nouveaustyle;
            }
        }
    }
    else
        for (const auto &type : _styles) {
            NoeudPtr nouveaustyle = type.second;

            for (auto &element : _elements) {
                auto elementstyle = std::dynamic_pointer_cast<BaliseStyle>(element);

                if (elementstyle && elementstyle->type_balise() == type.first) {
                    elementstyle->style() = nouveaustyle;
                }
            }
        }
}

void Page::finaliser_html(const Contexte & contexte) const {
    regrouper_commentaires(contexte);
    appliquer_styles();
    _fini = true;
}
