#pragma once
#include <algorithm>
#include "noeud.hh"
#include "attribut.hh"

class Style : public Noeud
{
public:
    Style() : _attributs(std::map<Attribut_t, NoeudPtr>()) {}
    Style(const Style &) =default;

    std::string toHTML(const Contexte & contexte) const override;

    void ajouterStyle(NoeudPtr attribut);
private:
    std::map<Attribut_t, NoeudPtr> _attributs;
};
