#pragma once
#include "baliseStyle.hh"

class BaliseParagraphe : public BaliseStyle
{
public:
    BaliseParagraphe() =delete;
    BaliseParagraphe(const BaliseParagraphe &) =default;
    BaliseParagraphe(NoeudPtr text, NoeudPtr style);

    std::string nomBalise() const override;
};
