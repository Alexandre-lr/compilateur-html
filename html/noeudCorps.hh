#pragma once
#include <vector>
#include "noeud.hh"

class NoeudCorps : public Noeud
{
public:
    NoeudCorps() =default;
    NoeudCorps(const NoeudCorps &) =default;

    std::string toHTML(const Contexte & contexte) const override;

    void ajouterElement(NoeudPtr element);
private:
    std::vector<NoeudPtr> _elements;
};
