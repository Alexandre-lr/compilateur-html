#include <iostream>
#include "contexte.hh"
#include "couleur.hh"
#include "attribut.hh"
#include "text.hh"
#include "style.hh"
#include "baliseTitre.hh"
#include "baliseImage.hh"
#include "noeudCorps.hh"
#include "noeudEnTete.hh"
#include "page.hh"

int main() {
    Contexte c1;

    std::shared_ptr<NoeudCorps> corps = std::make_shared<NoeudCorps>();
    std::shared_ptr<NoeudEnTete> entete = std::make_shared<NoeudEnTete>();
    std::shared_ptr<Page> page = std::make_shared<Page>(corps, entete);
    NoeudPtr text1 = std::make_shared<Text>("text1");
    NoeudPtr couleur1 = std::make_shared<Couleur>(255, 255, 255);
    NoeudPtr couleur2 = std::make_shared<Couleur>(255, 255, 0);
    NoeudPtr css1 = std::make_shared<Text>("styles.css");
    NoeudPtr encodage1 = std::make_shared<Text>("ISO-8859-1");
    NoeudPtr attribut1 = std::make_shared<Attribut>(Attribut_t::couleurTexte, couleur1);
    NoeudPtr attribut2 = std::make_shared<Attribut>(Attribut_t::couleurTexte, couleur2);
    NoeudPtr propriete1 = std::make_shared<Propriete>(Propriete_t::css, css1);
    NoeudPtr propriete2 = std::make_shared<Propriete>(Propriete_t::encodage, encodage1);

    std::shared_ptr<Style> style1 = std::make_shared<Style>();
    style1->ajouterStyle(attribut1);
    std::shared_ptr<Style> style2 = std::make_shared<Style>();
    style2->ajouterStyle(attribut2);

    entete->ajouterPropriete(propriete1);
    entete->modifier_titre(text1);
    entete->ajouterPropriete(propriete2);

    NoeudPtr titre1 = std::make_shared<BaliseTitre>(text1, style1, 9);
    NoeudPtr titre2 = std::make_shared<BaliseTitre>(text1, style2, 1);
    NoeudPtr image1 = std::make_shared<BaliseImage>(text1);

    corps->ajouterElement(titre1);

    std::cout << page->toHTML(c1) << std::endl;

    page->sauvegarde("./final.html", c1);

    return 0;
}

