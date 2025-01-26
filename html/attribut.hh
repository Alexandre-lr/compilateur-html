#pragma once
#include "noeud.hh"

enum class Attribut_t {
    largeur,
    hauteur,
    couleurTexte,
    couleurFond,
    opacite,
};

class Attribut : public Noeud
{
public:
    Attribut() =delete;
    Attribut(const Attribut &) =default;
    Attribut(Attribut_t type, NoeudPtr valeur);

    std::string toHTML(const Contexte & contexte) const override;

    // Pour ajouterStyle de style.hh
    Attribut_t const & type() const;
private:
    Attribut_t _type;
    NoeudPtr _valeur;
};
