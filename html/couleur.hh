#pragma once
#include <cstdint>
#include <iomanip>
#include <string>
#include <sstream>
#include "noeud.hh"

class Couleur : public Noeud
{
public:
    Couleur() =delete;
    Couleur(const Couleur &) =default;
    Couleur(NoeudPtr r, NoeudPtr v, NoeudPtr b);
    Couleur(NoeudPtr couleurHex);

    std::string to_html(const Contexte & contexte) const override;
private:
    std::uint8_t _r;
    std::uint8_t _v;
    std::uint8_t _b;
};
