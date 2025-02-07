    #pragma once
    #include "noeud.hh"

    enum class Attribut_t {
        largeur,
        hauteur,
        couleurTexte,
        couleurFond,
        opacite,
    };

    class Attribut : public Noeud
    {
    public:
        Attribut() =delete;
        Attribut(const Attribut &) =default;
        Attribut(Attribut_t type, NoeudPtr valeur);

        std::string to_html(const Contexte & contexte) const override;

        Attribut& operator=(const Attribut & a);
        Attribut_t const & type() const;
    private:
        Attribut_t _type;
        NoeudPtr _valeur;
    };
