#pragma once
#include <string>
#include <vector>
#include "noeudElement.hh"
#include "style.hh"

class BaliseStyle : public NoeudElement
{
public:
    BaliseStyle() =delete;
    BaliseStyle(const BaliseStyle &) =default;
    BaliseStyle(NoeudPtr contenu, NoeudPtr style);

    std::string toHTML(const Contexte & contexte) const override;


private:
    NoeudPtr _style;
};
