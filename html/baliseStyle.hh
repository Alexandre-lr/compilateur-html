#pragma once
#include <string>
#include <vector>
#include "noeudElement.hh"
#include "attribut.hh"

class BaliseStyle : public NoeudElement
{
public:
    BaliseStyle() =delete;
    BaliseStyle(const BaliseStyle &) =default;
    BaliseStyle(NoeudPtr contenu, NoeudPtr style);

    std::string to_html(const Contexte & contexte) const override;

    // Déclaration d'opérateur personnalisé
    NoeudPtr& style();
    NoeudPtr& attribut(Attribut::Attribut_t attribut);

    // Modifie seulement l'attribut, ne le retourne pas
    void modifier_attribut(NoeudPtr attribut);
private:
    NoeudPtr _style;
};
