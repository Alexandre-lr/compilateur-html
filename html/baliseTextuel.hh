#pragma once
#include "noeudElement.hh"

class BaliseTextuel : public NoeudElement
{
public:
    BaliseTextuel() =delete;
    BaliseTextuel(const BaliseTextuel &) =default;
    BaliseTextuel(NoeudPtr text);

    NoeudPtr text() const;
private:
    NoeudPtr _text;
};
