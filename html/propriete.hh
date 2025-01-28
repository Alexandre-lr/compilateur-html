#pragma once
#include "noeud.hh"

enum class Propriete_t {
    encodage,
    icone,
    css,
    langue,
};

class Propriete : public Noeud
{
public:
    Propriete() =delete;
    Propriete(const Propriete &) =default;
    Propriete(Propriete_t type, NoeudPtr valeur);

    std::string to_html(const Contexte & contexte) const override;

    Propriete_t const & type() const;
private:
    Propriete_t _type;
    NoeudPtr _valeur;
};
