#pragma once
#include "noeud.hh"

class Constante : public Noeud
{
public:
    Constante() {}
private:
    double _valeur;
};
