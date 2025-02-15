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

    appliquer_styles();

    // Construction du parser à l'envers
    std::reverse(_commentaires.begin(), _commentaires.end());
    std::reverse(_blocs.begin(), _blocs.end());
    std::string corps("\t<body>\n");
    if (!_commentaires.empty()) {
        corps += "\t\t<!--\n";
        for (auto const & commentaire : _commentaires)
            corps += commentaire->to_html(contexte);
        corps += "\t\t-->\n";
    }

    for (auto const & bloc : _blocs)
        corps += bloc->to_html(contexte);
    corps += "\t</body>\n";

    std::string page("<!DOCTYPE html>\n");
    page += entete;
    page += corps;
    page += "</html>\n";

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

NoeudPtr& Page::bloc(NoeudPtr idx, NoeudElement::Bloc_t type) {
    auto indice(std::dynamic_pointer_cast<Constante>(idx)->valeur());

    auto i(0);
    for (auto & ibloc : _blocs) {
        auto bloc(std::dynamic_pointer_cast<NoeudElement>(ibloc));

        if (bloc && (bloc->type_balise() == type)) {
            if (i == indice)
                return ibloc;
            else
                i++;
        }
    }
    throw std::out_of_range("Selecteur invalide : élément introuvable pour l'indice " + std::to_string(indice) + " et le type donné.");
}

void Page::ajouter_bloc(NoeudPtr bloc) {
    auto nouveaubloc(std::dynamic_pointer_cast<NoeudElement>(bloc));

    if (nouveaubloc->type_balise() != NoeudElement::Bloc_t::commentaire)
        _blocs.push_back(std::move(bloc));
    else
        throw std::invalid_argument("Type invalide : Noeud-Bloc attendu.");
}

void Page::ajouter_commentaire(NoeudPtr commentaire)  {
    auto nouveaucommentaire(std::dynamic_pointer_cast<BaliseCommentaire>(commentaire));

    if (nouveaucommentaire)
        _commentaires.push_back(std::move(commentaire));
    else
        throw std::invalid_argument("Type invalide : Noeud-Commentaire attendu.");
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

void Page::appliquer_styles() const {
    auto stylepage = _styles.find(NoeudElement::Bloc_t::page);
    if (stylepage != _styles.end()) {
        NoeudPtr nouveaustyle = stylepage->second;

        for (auto &bloc : _blocs) {
            auto blocstyle = std::dynamic_pointer_cast<BaliseStyle>(bloc);

            if (blocstyle) {
                blocstyle->style() = nouveaustyle;
            }
        }
    }
    else
        for (const auto &type : _styles) {
            NoeudPtr nouveaustyle = type.second;

            for (auto &bloc : _blocs) {
                auto blocstyle = std::dynamic_pointer_cast<BaliseStyle>(bloc);

                if (blocstyle && blocstyle->type_balise() == type.first) {
                    blocstyle->style() = nouveaustyle;
                }
            }
        }
}
