#pragma once
#include "noeud.hh"
#include "propriete.hh"

class NoeudEnTete : public Noeud
{
public:
    NoeudEnTete();
    NoeudEnTete(const NoeudEnTete &) =default;

    std::string toHTML(const Contexte & contexte) const override;

    const NoeudPtr & langue() const;
    void ajouterPropriete(NoeudPtr propriete);
    void modifier_titre(NoeudPtr titre);
private:
    std::map<Propriete_t, NoeudPtr> _proprietes;
    NoeudPtr _titre;
};
