#pragma once
#include "noeud.hh"

class Propriete : public Noeud
{
public:
    enum class Propriete_t {
        encodage,
        icone,
        css,
        langue,
    };

    Propriete() =delete;
    Propriete(const Propriete &) =default;
    Propriete(Propriete_t type, NoeudPtr valeur);

    std::string to_html(const Contexte & contexte) const override;

    Propriete_t const & type_propriete() const;
private:
    Propriete_t _type;
    NoeudPtr _valeur;
};
