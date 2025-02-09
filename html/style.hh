#pragma once
#include <algorithm>
#include "noeud.hh"
#include "attribut.hh"
#include "noeudElement.hh"

class Style : public Noeud
{
public:
    Style();
    Style(NoeudElement::Bloc_t cible);
    Style(const Style &) =default;

    std::string to_html(const Contexte & contexte) const override;

    // Déclaration d'opérateur personnalisé
    NoeudPtr& attribut(Attribut::Attribut_t type);
    void modifier_attribut(NoeudPtr attribut);

    Style& operator=(const Style & s);

    NoeudElement::Bloc_t cible() const;
private:
    std::map<Attribut::Attribut_t, NoeudPtr> _attributs = std::map<Attribut::Attribut_t, NoeudPtr>();
    NoeudElement::Bloc_t _cible;
};
