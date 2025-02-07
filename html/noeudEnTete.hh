#pragma once
#include "noeud.hh"
#include "propriete.hh"
#include "text.hh"

class NoeudEnTete : public Noeud
{
public:
    NoeudEnTete() =default;
    NoeudEnTete(const NoeudEnTete &) =default;

    std::string to_html(const Contexte & contexte) const override;

    void modifier_propriete(NoeudPtr propriete);
    void modifier_titre(NoeudPtr titre);
protected:
    const NoeudPtr & langue() const;
private:
    std::map<Propriete_t, NoeudPtr> _proprietes = std::map<Propriete_t, NoeudPtr>({
                                                    {Propriete_t::langue, std::make_shared<Propriete>(Propriete_t::langue, std::make_shared<Text>("fr"))},
                                                    {Propriete_t::encodage, std::make_shared<Propriete>(Propriete_t::encodage, std::make_shared<Text>("utf-8"))}
                                            });
    NoeudPtr _titre = std::make_shared<Text>("");
};
