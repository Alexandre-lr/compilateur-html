#pragma once
#include "noeudElement.hh"

class BaliseCommentaire : public NoeudElement
{
public:
    BaliseCommentaire() =delete;
    BaliseCommentaire(const BaliseCommentaire &) =default;
    BaliseCommentaire(NoeudPtr text);

    std::string toHTML(const Contexte & contexte) const override;

    std::string nomBalise() const override;
};
