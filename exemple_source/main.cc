#include <iostream>
#include "contexte.hh"
#include "couleur.hh"
#include "attribut.hh"
#include "text.hh"
#include "constante.hh"
#include "style.hh"
#include "baliseTitre.hh"
#include "baliseImage.hh"
#include "baliseParagraphe.hh"
#include "baliseCommentaire.hh"
#include "noeudCorps.hh"
#include "noeudEnTete.hh"
#include "page.hh"

int main() {
    Contexte c1;

    std::shared_ptr<NoeudCorps> corps = std::make_shared<NoeudCorps>();
    std::shared_ptr<NoeudEnTete> entete = std::make_shared<NoeudEnTete>();
    std::shared_ptr<Page> page = std::make_shared<Page>(corps, entete);

    // Exemple 1

    // Exemple 2
//    NoeudPtr text1 = std::make_shared<Text>("ISO-8859-1");
//    NoeudPtr propriete1 = std::make_shared<Propriete>(Propriete_t::encodage, text1);
//    entete->modifier_propriete(propriete1);
//    NoeudPtr text2 = std::make_shared<Text>("Utilisation de l'encodage ISO-8859-1 pour faire apparaître des caractères erronés");
//    NoeudPtr commentaire1 = std::make_shared<BaliseCommentaire>(text2);
//    corps->ajouter_element(commentaire1);
//    NoeudPtr text3 = std::make_shared<Text>("rick.ico");
//    NoeudPtr propriete2 = std::make_shared<Propriete>(Propriete_t::icone, text3);
//    entete->modifier_propriete(propriete2);
//    NoeudPtr text4 = std::make_shared<Text>("Une\nJolie\nIcone");
//    NoeudPtr commentaire2 = std::make_shared<BaliseCommentaire>(text4);
//    corps->ajouter_element(commentaire2);
//    NoeudPtr text5 = std::make_shared<Text>("fr");
//    NoeudPtr propriete3 = std::make_shared<Propriete>(Propriete_t::langue, text5);
//    entete->modifier_propriete(propriete3);
//    NoeudPtr text6 = std::make_shared<Text>("rickroll 2");
//    entete->modifier_titre(text6);
//    NoeudPtr style1 = std::make_shared<Style>();
//    NoeudPtr text7 = std::make_shared<Text>("Un Problème ?");
//    NoeudPtr titre1 = std::make_shared<BaliseTitre>(text7, style1, 1);
//    corps->ajouter_element(titre1);
//    NoeudPtr text8 = std::make_shared<Text>("Le caractère è ne doit pas apparaître correctement");
//    NoeudPtr commentaire3 = std::make_shared<BaliseCommentaire>(text8);
//    corps->ajouter_element(commentaire3);

    //Exemple 3

    // Exemple 4
//    NoeudPtr couleur1 = std::make_shared<Couleur>(100, 255, 100);
//    NoeudPtr attribut1 = std::make_shared<Attribut>(Attribut_t::couleurTexte, couleur1);
//    corps->ajouter_attribut(attribut1, "h1");
//    NoeudPtr couleur2 = std::make_shared<Couleur>("#00000");
//    NoeudPtr attribut2 = std::make_shared<Attribut>(Attribut_t::couleurFond, couleur2);
//    corps->ajouter_attribut(attribut2, "h1");
//    NoeudPtr style1 = std::make_shared<Style>();
//    NoeudPtr text1 = std::make_shared<Text>("Premier Titre");
//    NoeudPtr titre1 = std::make_shared<BaliseTitre>(text1, style1, 1);
//    corps->ajouter_element(titre1);
//    NoeudPtr text2 = std::make_shared<Text>("Premier sous-titre");
//    NoeudPtr titre2 = std::make_shared<BaliseTitre>(text2, style1, 2);
//    corps->ajouter_element(titre2);
//    NoeudPtr text3 = std::make_shared<Text>("Deuxieme Titre");
//    NoeudPtr titre3 = std::make_shared<BaliseTitre>(text3, style1, 1);
//    corps->ajouter_element(titre3);

    // Exemple 5
//    NoeudPtr constante1 = std::make_shared<Constante>(1);
//    c1["indice"] = constante1;
//    NoeudPtr couleur1 = std::make_shared<Couleur>(std::make_shared<Text>("#ff0000"));
//    NoeudPtr attribut1 = std::make_shared<Attribut>(Attribut_t::couleurFond, couleur1);
//    NoeudPtr couleur2 = std::make_shared<Couleur>(0, 255, 0);
//    NoeudPtr attribut2 = std::make_shared<Attribut>(Attribut_t::couleurFond, couleur2);
//    NoeudPtr style1 = std::make_shared<Style>();
//    NoeudPtr text1 = std::make_shared<Text>("Premier paragraphe");
//    NoeudPtr paragraphe1 = std::make_shared<BaliseParagraphe>(text1, style1);
//    corps->ajouter_element(paragraphe1);
//    NoeudPtr style2 = std::make_shared<Style>();
//    NoeudPtr text2 = std::make_shared<Text>("Deuxieme paragraphe");
//    NoeudPtr paragraphe2 = std::make_shared<BaliseParagraphe>(text2, style2);
//    corps->ajouter_element(paragraphe2);
//    NoeudPtr style3 = std::make_shared<Style>();
//    NoeudPtr text3 = std::make_shared<Text>("Troisieme paragraphe");
//    NoeudPtr paragraphe3 = std::make_shared<BaliseParagraphe>(text3, style3);
//    corps->ajouter_element(paragraphe3);
//    c1["bloc"] = corps->element(std::dynamic_pointer_cast<Constante>(c1.get("indice"))->valeur(), "p");
//    std::dynamic_pointer_cast<BaliseStyle>(c1.get("bloc"))->modifier_attribut(attribut1);
//    NoeudPtr style4 = std::make_shared<Style>();
//    std::dynamic_pointer_cast<Style>(style4)->modifier_attribut(attribut2);
//    c1["bloc"] = corps->element(std::dynamic_pointer_cast<Constante>(c1.get("indice"))->valeur()-1, "p");
//    std::dynamic_pointer_cast<BaliseStyle>(c1.get("bloc"))->style() = style4;
//    std::cout << page->to_html(c1) << std::endl;

    page->sauvegarder("./final.html", c1);
    return 0;
}

