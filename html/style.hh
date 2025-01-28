#pragma once
#include <algorithm>
#include "noeud.hh"
#include "attribut.hh"

class Style : public Noeud
{
public:
    Style() : _attributs(std::map<Attribut_t, NoeudPtr>()) {}
    Style(const Style &) =default;

    std::string to_html(const Contexte & contexte) const override;

    NoeudPtr& attribut(Attribut_t type);
    Style& operator=(const Style & s);
private:
    std::map<Attribut_t, NoeudPtr> _attributs;
};
