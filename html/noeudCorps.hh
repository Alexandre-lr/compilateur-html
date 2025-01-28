#pragma once
#include <vector>
#include "noeud.hh"

class NoeudCorps : public Noeud
{
public:
    NoeudCorps() =default;
    NoeudCorps(const NoeudCorps &) =default;

    std::string to_html(const Contexte & contexte) const override;

    NoeudPtr& element(const std::size_t & idx, const std::string & balise);

    void ajouter_element(NoeudPtr element);
    void ajouter_attribut(NoeudPtr style, std::string type);
private:
    mutable std::vector<NoeudPtr> _elements;
    mutable bool _fini = false;
    std::map<std::string, NoeudPtr> _styles;

    void regrouper_commentaires(const Contexte & contexte) const;
    void appliquer_styles() const;
    void finaliser_html(const Contexte & contexte) const;
};
