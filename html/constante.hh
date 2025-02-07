#pragma once
#include "noeud.hh"

class Constante : public Noeud
{
public:
    Constante() =delete;
    Constante(const Constante &) =default;
    Constante(int valeur);

    std::string to_html(const Contexte & contexte) const;

    int valeur() const;
private:
    int _valeur;
};
