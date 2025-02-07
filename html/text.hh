#pragma once
#include "noeud.hh"

class Text : public Noeud
{
public:
    Text() =delete;
    Text(const Text &) =default;
    Text(std::string const & valeur);

    std::string to_html(const Contexte & contexte) const override;

    std::string& valeur();
private:
    std::string _valeur;
};
