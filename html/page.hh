#pragma once
#include <fstream>
#include <vector>
#include "noeud.hh"
#include "noeudElement.hh"
#include "propriete.hh"
#include "texte.hh"

class Page : public Noeud
{
public:
    Page() {}
    Page(const Page &) =default;

    std::string to_html(const Contexte & contexte) const override;

    void sauvegarder(const std::string & dest, const Contexte & contexte) const;

    NoeudPtr& element(NoeudPtr idx, NoeudElement::Bloc_t type);

    void ajouter_element(NoeudPtr element);
    void ajouter_style(NoeudPtr style);
    void modifier_propriete(NoeudPtr propriete);
    void modifier_titre(NoeudPtr titre);
protected:
    const NoeudPtr & langue() const;
private:
    void regrouper_commentaires(const Contexte & contexte) const;
    void appliquer_styles() const;
    void finaliser_html(const Contexte & contexte) const;
private:
    std::map<Propriete::Propriete_t, NoeudPtr> _proprietes = std::map<Propriete::Propriete_t, NoeudPtr>({
        {Propriete::Propriete_t::langue,   std::make_shared<Propriete>(Propriete::Propriete_t::langue,   std::make_shared<Texte>("fr"))},
        {Propriete::Propriete_t::encodage, std::make_shared<Propriete>(Propriete::Propriete_t::encodage, std::make_shared<Texte>("utf-8"))}
    });
    NoeudPtr _titre = std::make_shared<Texte>("");
    mutable std::vector<NoeudPtr> _elements;
    std::map<NoeudElement::Bloc_t, NoeudPtr> _styles;
    mutable bool _fini = false;
};
