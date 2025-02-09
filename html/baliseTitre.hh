#pragma once
#include <cstdint>
#include "baliseStyle.hh"

class BaliseTitre : public BaliseStyle
{
public:
    BaliseTitre() =delete;
    BaliseTitre(const BaliseTitre &) =default;
    BaliseTitre(NoeudPtr texte, NoeudPtr style, const std::uint8_t & niveau);

    NoeudElement::Bloc_t type_balise() const override;
private:
    std::uint8_t _niveau;
};
