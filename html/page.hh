#pragma once
#include <fstream>
#include "noeud.hh"

class Page : public Noeud
{
public:
    Page(NoeudPtr corps, NoeudPtr entete);
    Page(const Page &) =default;

    std::string to_html(const Contexte & contexte) const override;

    void sauvegarder(const std::string & dest, const Contexte & contexte) const;
private:
    NoeudPtr _corps;
    NoeudPtr _entete;
};
