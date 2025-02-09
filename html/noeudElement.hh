#pragma once
#include "noeud.hh"

class NoeudElement : public Noeud
{
public:
    enum class Bloc_t {
        page,
        paragraphe,
        titre1,
        titre2,
        titre3,
        titre4,
        titre5,
        titre6,
        titre7,
        titre8,
        titre9,
        commentaire,
        image,
    };

    NoeudElement() =delete;
    NoeudElement(const NoeudElement &) =default;
    NoeudElement(const NoeudPtr & contenu);

    virtual Bloc_t type_balise() const =0;
    NoeudPtr contenu() const;
protected:
    std::string tag() const;
private:
    NoeudPtr _contenu;
};

// Pour debug
std::ostream& operator<<(std::ostream& os, const NoeudElement::Bloc_t& bloc);
