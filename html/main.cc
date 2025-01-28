#include <iostream>
#include "contexte.hh"
#include "couleur.hh"
#include "attribut.hh"
#include "text.hh"
#include "style.hh"
#include "baliseTitre.hh"
#include "baliseImage.hh"
#include "baliseParagrahpe.hh"
#include "noeudCorps.hh"
#include "noeudEnTete.hh"
#include "page.hh"

int main() {
    Contexte c1;

    std::shared_ptr<NoeudCorps> corps = std::make_shared<NoeudCorps>();
    std::shared_ptr<NoeudEnTete> entete = std::make_shared<NoeudEnTete>();
    std::shared_ptr<Page> page = std::make_shared<Page>(corps, entete);
    NoeudPtr text1 = std::make_shared<Text>("text1");
    NoeudPtr text2 = std::make_shared<Text>("text2");
    NoeudPtr couleur1 = std::make_shared<Couleur>(255, 255, 255);
    NoeudPtr couleur2 = std::make_shared<Couleur>(255, 255, 0);
    NoeudPtr couleur3 = std::make_shared<Couleur>(255, 0, 0);
    NoeudPtr css1 = std::make_shared<Text>("styles.css");
    NoeudPtr encodage1 = std::make_shared<Text>("ISO-8859-1");
    NoeudPtr attribut1 = std::make_shared<Attribut>(Attribut_t::couleurTexte, couleur1);
    NoeudPtr attribut2 = std::make_shared<Attribut>(Attribut_t::couleurTexte, couleur2);
    NoeudPtr attribut3 = std::make_shared<Attribut>(Attribut_t::couleurFond, couleur3);
    NoeudPtr propriete1 = std::make_shared<Propriete>(Propriete_t::css, css1);
    NoeudPtr propriete2 = std::make_shared<Propriete>(Propriete_t::encodage, encodage1);

    std::shared_ptr<Style> style1 = std::make_shared<Style>();
//    style1->modifier_attribut(attribut1);
    std::shared_ptr<Style> style2 = std::make_shared<Style>();
//    style2->modifier_attribut(attribut2);
//    style2->modifier_attribut(attribut3);

    entete->modifier_propriete(propriete1);
    entete->modifier_titre(text1);
    entete->modifier_propriete(propriete2);

    NoeudPtr titre1 = std::make_shared<BaliseTitre>(text1, style1, 1);
    NoeudPtr titre2 = std::make_shared<BaliseTitre>(text2, style2, 1);
    NoeudPtr image1 = std::make_shared<BaliseImage>(text1);
    NoeudPtr paragraphe1 = std::make_shared<BaliseParagraphe>(text1, style1);

    corps->ajouter_element(titre1);
    corps->ajouter_element(paragraphe1);
    corps->ajouter_element(titre2);


    c1["maVariableBloc"] = corps->element(1, std::dynamic_pointer_cast<BaliseTitre>(titre2)->nom_balise());
    std::dynamic_pointer_cast<BaliseTitre>(c1["maVariableBloc"])->attribut(Attribut_t::couleurFond) = attribut3;
//    std::cout << c1.get("maVariableBloc")->to_html(c1) << std::endl;
    std::cout << page->to_html(c1) << std::endl;

    page->sauvegarder("./final.html", c1);
    return 0;
}

