#pragma once
#include <fstream>
#include "noeud.hh"

class Page : public Noeud
{
public:
    Page(NoeudPtr corps, NoeudPtr entete);
    Page(const Page &) =default;

    std::string toHTML(const Contexte & contexte) const override;

    void sauvegarde(const std::string & dest, const Contexte & contexte) const;
private:
    NoeudPtr _corps;
    NoeudPtr _entete;
};
