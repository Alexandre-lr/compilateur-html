#pragma once
#include "noeud.hh"

class Constante : public Noeud
{
public:
    Constante() =delete;
    Constante(const Constante &) =default;
    Constante(double valeur);

    std::string to_html(const Contexte & contexte) const;

    double valeur() const;
private:
    double _valeur;
};
