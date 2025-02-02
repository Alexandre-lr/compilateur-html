#pragma once
#include "noeud.hh"

class NoeudElement : public Noeud
{
public:
    NoeudElement() =delete;
    NoeudElement(const NoeudElement &) =default;
    NoeudElement(const NoeudPtr & contenu);

    virtual std::string nom_balise() const =0;
    NoeudPtr contenu() const;
private:
    NoeudPtr _contenu;
};
