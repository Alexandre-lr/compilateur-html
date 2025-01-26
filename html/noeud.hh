#pragma once
#include <memory>
#include "contexte.hh"

class Contexte;

class Noeud
{
public:
    virtual std::string toHTML(const Contexte & contexte) const =0;
};

using NoeudPtr = std::shared_ptr<Noeud>;
