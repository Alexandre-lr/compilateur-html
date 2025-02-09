#pragma once
#include "noeudElement.hh"

class BaliseCommentaire : public NoeudElement
{
public:
    BaliseCommentaire() =delete;
    BaliseCommentaire(const BaliseCommentaire &) =default;
    BaliseCommentaire(NoeudPtr texte);

    std::string to_html(const Contexte & contexte) const override;

    NoeudElement::Bloc_t type_balise() const override;
};
