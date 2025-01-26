#pragma once
#include "noeudElement.hh"

class BaliseImage : public NoeudElement
{
public:
    BaliseImage() =delete;
    BaliseImage(const BaliseImage &) =default;
    BaliseImage(NoeudPtr src);

    std::string toHTML(const Contexte & contexte) const override;

    std::string nomBalise() const override;
};
