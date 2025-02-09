#pragma once
#include "baliseStyle.hh"

class BaliseParagraphe : public BaliseStyle
{
public:
    BaliseParagraphe() =delete;
    BaliseParagraphe(const BaliseParagraphe &) =default;
    BaliseParagraphe(NoeudPtr texte, NoeudPtr style);

    NoeudElement::Bloc_t type_balise() const override;
};
