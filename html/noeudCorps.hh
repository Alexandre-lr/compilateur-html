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
private:
    std::vector<NoeudPtr> _elements;
};
