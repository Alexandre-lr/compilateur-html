#pragma once
#include "noeudElement.hh"

class BaliseCommentaire : public NoeudElement
{
public:
    BaliseCommentaire() =delete;
    BaliseCommentaire(const BaliseCommentaire &) =default;
    BaliseCommentaire(NoeudPtr text);

    std::string to_html(const Contexte & contexte) const override;

    std::string nom_balise() const override;
};
