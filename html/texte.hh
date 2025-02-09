#pragma once
#include "noeud.hh"

class Texte : public Noeud
{
public:
    Texte() =delete;
    Texte(const Texte &) =default;
    Texte(std::string const & valeur);

    std::string to_html(const Contexte & contexte) const override;

    std::string & valeur();
private:
    std::string _valeur;
};
