#pragma once
#include "noeudElement.hh"

class BaliseImage : public NoeudElement
{
public:
    BaliseImage() =delete;
    BaliseImage(const BaliseImage &) =default;
    BaliseImage(NoeudPtr src);

    std::string to_html(const Contexte & contexte) const override;

    NoeudElement::Bloc_t type_balise() const override;
};
