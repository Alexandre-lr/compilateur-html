#include <iostream>
#include "contexte.hh"
#include "couleur.hh"
#include "attribut.hh"
#include "texte.hh"
#include "constante.hh"
#include "style.hh"
#include "baliseTitre.hh"
#include "baliseImage.hh"
#include "baliseParagraphe.hh"
#include "baliseCommentaire.hh"
#include "page.hh"

int main() {
    Contexte c1;

    NoeudPtr page = std::make_shared<Page>();

    std::shared_ptr<Page> page_ptr = std::dynamic_pointer_cast<Page>(page);

    // Exemple 1
//    NoeudPtr texte1 = std::make_shared<Texte>("Ma super page");
//    NoeudPtr titre1 = std::make_shared<BaliseTitre>(texte1, std::make_shared<Style>(), 1);
//    page_ptr->ajouter_element(titre1);
//    NoeudPtr texte2 = std::make_shared<Texte>("Quelques paragraphes");
//    NoeudPtr titre2 = std::make_shared<BaliseTitre>(texte2, std::make_shared<Style>(), 2);
//    page_ptr->ajouter_element(titre2);
//    NoeudPtr texte3 = std::make_shared<Texte>("Ceci est mon premier paragraphe court");
//    NoeudPtr paragraphe1 = std::make_shared<BaliseParagraphe>(texte3, std::make_shared<Style>());
//    page_ptr->ajouter_element(paragraphe1);
//    // Retour à la ligne géré dans le parser (à voir)
//    NoeudPtr texte4 = std::make_shared<Texte>("Un paragraphe Un peu plus long sur trois lignes");
//    NoeudPtr paragraphe2 = std::make_shared<BaliseParagraphe>(texte4, std::make_shared<Style>());
//    page_ptr->ajouter_element(paragraphe2);
//    NoeudPtr texte5 = std::make_shared<Texte>("Une image pour le fun");
//    NoeudPtr titre4 = std::make_shared<BaliseTitre>(texte5, std::make_shared<Style>(), 2);
//    page_ptr->ajouter_element(titre4);
//    NoeudPtr texte6 = std::make_shared<Texte>("rick.jpg");
//    NoeudPtr image1 = std::make_shared<BaliseImage>(texte6);
//    page_ptr->ajouter_element(image1);
//    NoeudPtr texte7 = std::make_shared<Texte>("Rickroll");
//    NoeudPtr titre5 = std::make_shared<BaliseTitre>(texte7, std::make_shared<Style>(), 3);
//    page_ptr->ajouter_element(titre5);

    // Exemple 2
//    NoeudPtr texte1 = std::make_shared<Texte>("ISO-8859-1");
//    NoeudPtr propriete1 = std::make_shared<Propriete>(Propriete::Propriete_t::encodage, texte1);
//    page_ptr->modifier_propriete(propriete1);
//    NoeudPtr texte2 = std::make_shared<Texte>("Utilisation de l'encodage ISO-8859-1 pour faire apparaître des caractères erronés");
//    NoeudPtr commentaire1 = std::make_shared<BaliseCommentaire>(texte2);
//    page_ptr->ajouter_element(commentaire1);
//    NoeudPtr texte3 = std::make_shared<Texte>("rickICO.jpg");
//    NoeudPtr propriete2 = std::make_shared<Propriete>(Propriete::Propriete_t::icone, texte3);
//    page_ptr->modifier_propriete(propriete2);
//    NoeudPtr texte4 = std::make_shared<Texte>("Une\nJolie\nIcone");
//    NoeudPtr commentaire2 = std::make_shared<BaliseCommentaire>(texte4);
//    page_ptr->ajouter_element(commentaire2);
//    NoeudPtr texte5 = std::make_shared<Texte>("fr");
//    NoeudPtr propriete3 = std::make_shared<Propriete>(Propriete::Propriete_t::langue, texte5);
//    page_ptr->modifier_propriete(propriete3);
//    NoeudPtr texte6 = std::make_shared<Texte>("rickroll 2");
//    page_ptr->modifier_titre(texte6);
//    NoeudPtr style1 = std::make_shared<Style>();
//    NoeudPtr texte7 = std::make_shared<Texte>("Un Problème ?");
//    NoeudPtr titre1 = std::make_shared<BaliseTitre>(texte7, style1, 1);
//    page_ptr->ajouter_element(titre1);
//    NoeudPtr texte8 = std::make_shared<Texte>("Le caractère è ne doit pas apparaître correctement");
//    NoeudPtr commentaire3 = std::make_shared<BaliseCommentaire>(texte8);
//    page_ptr->ajouter_element(commentaire3);

    //Exemple 3
//    NoeudPtr style1 = std::make_shared<Style>();
//    NoeudPtr couleur1 = std::make_shared<Couleur>(std::make_shared<Constante>(255), std::make_shared<Constante>(0), std::make_shared<Constante>(0));
//    NoeudPtr attribut1 = std::make_shared<Attribut>(Attribut::Attribut_t::couleurTexte, couleur1);
//    std::dynamic_pointer_cast<Style>(style1)->modifier_attribut(attribut1);
//    NoeudPtr couleur2 = std::make_shared<Couleur>(std::make_shared<Texte>("#00FF00"));
//    NoeudPtr attribut2 = std::make_shared<Attribut>(Attribut::Attribut_t::couleurFond, couleur2);
//    std::dynamic_pointer_cast<Style>(style1)->modifier_attribut(attribut2);
//    NoeudPtr attribut3 = std::make_shared<Attribut>(Attribut::Attribut_t::opacite, std::make_shared<Texte>("50%"));
//    std::dynamic_pointer_cast<Style>(style1)->modifier_attribut(attribut3);
//    NoeudPtr texte1 = std::make_shared<Texte>("Ceci est un long texte");
//    NoeudPtr titre1 = std::make_shared<BaliseTitre>(texte1, style1, 1);
//    page_ptr->ajouter_element(titre1);
//    NoeudPtr style2 = std::make_shared<Style>();
//    NoeudPtr texte2 = std::make_shared<Texte>("1000px");
//    NoeudPtr attribut4 = std::make_shared<Attribut>(Attribut::Attribut_t::largeur, texte2);
//    std::dynamic_pointer_cast<Style>(style2)->modifier_attribut(attribut4);
//    NoeudPtr texte3 = std::make_shared<Texte>("500px");
//    NoeudPtr attribut5 = std::make_shared<Attribut>(Attribut::Attribut_t::hauteur, texte3);
//    std::dynamic_pointer_cast<Style>(style2)->modifier_attribut(attribut5);
//    NoeudPtr couleur3 = std::make_shared<Couleur>(std::make_shared<Texte>("#0000ff"));
//    NoeudPtr attribut6 = std::make_shared<Attribut>(Attribut::Attribut_t::couleurFond, couleur3);
//    std::dynamic_pointer_cast<Style>(style2)->modifier_attribut(attribut6);
//    NoeudPtr texte4 = std::make_shared<Texte>("Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.");
//    NoeudPtr paragraphe1 = std::make_shared<BaliseParagraphe>(texte4, style2);
//    page_ptr->ajouter_element(paragraphe1);

    // Exemple 4
//    NoeudPtr style1 = std::make_shared<Style>(NoeudElement::Bloc_t::titre1);
//    NoeudPtr couleur1 = std::make_shared<Couleur>(std::make_shared<Constante>(100), std::make_shared<Constante>(255), std::make_shared<Constante>(100));
//    NoeudPtr attribut1 = std::make_shared<Attribut>(Attribut::Attribut_t::couleurTexte, couleur1);
//    std::dynamic_pointer_cast<Style>(style1)->modifier_attribut(attribut1);
//    NoeudPtr couleur2 = std::make_shared<Couleur>(std::make_shared<Texte>("#000000"));
//    NoeudPtr attribut2 = std::make_shared<Attribut>(Attribut::Attribut_t::couleurFond, couleur2);
//    std::dynamic_pointer_cast<Style>(style1)->modifier_attribut(attribut2);
//    page_ptr->ajouter_style(style1);
//    NoeudPtr texte1 = std::make_shared<Texte>("Premier Titre");
//    NoeudPtr titre1 = std::make_shared<BaliseTitre>(texte1, std::make_shared<Style>(), 1);
//    page_ptr->ajouter_element(titre1);
//    NoeudPtr texte2 = std::make_shared<Texte>("Premier sous-titre");
//    NoeudPtr titre2 = std::make_shared<BaliseTitre>(texte2, std::make_shared<Style>(), 2);
//    page_ptr->ajouter_element(titre2);
//    NoeudPtr texte3 = std::make_shared<Texte>("Deuxieme Titre");
//    NoeudPtr titre3 = std::make_shared<BaliseTitre>(texte3, std::make_shared<Style>(), 1);
//    page_ptr->ajouter_element(titre3);

    // Exemple 5
//    NoeudPtr constante1 = std::make_shared<Constante>(1);
//    c1["indice"] = constante1;
//    NoeudPtr couleur1 = std::make_shared<Couleur>(std::make_shared<Texte>("#ff0000"));
//    NoeudPtr attribut1 = std::make_shared<Attribut>(Attribut::Attribut_t::couleurFond, couleur1);
//    NoeudPtr couleur2 = std::make_shared<Couleur>(std::make_shared<Constante>(0), std::make_shared<Constante>(255), std::make_shared<Constante>(0));
//    NoeudPtr attribut2 = std::make_shared<Attribut>(Attribut::Attribut_t::couleurFond, couleur2);
//    NoeudPtr texte1 = std::make_shared<Texte>("Premier paragraphe");
//    NoeudPtr paragraphe1 = std::make_shared<BaliseParagraphe>(texte1, std::make_shared<Style>());
//    page_ptr->ajouter_element(paragraphe1);
//    NoeudPtr texte2 = std::make_shared<Texte>("Deuxieme paragraphe");
//    NoeudPtr paragraphe2 = std::make_shared<BaliseParagraphe>(texte2, std::make_shared<Style>());
//    page_ptr->ajouter_element(paragraphe2);
//    NoeudPtr texte3 = std::make_shared<Texte>("Troisieme paragraphe");
//    NoeudPtr paragraphe3 = std::make_shared<BaliseParagraphe>(texte3, std::make_shared<Style>());
//    page_ptr->ajouter_element(paragraphe3);
//    c1["bloc"] = page_ptr->element(std::dynamic_pointer_cast<Constante>(c1.get("indice"))->valeur(), NoeudElement::Bloc_t::paragraphe);
//    std::dynamic_pointer_cast<BaliseStyle>(c1.get("bloc"))->modifier_attribut(attribut1);
//    NoeudPtr style4 = std::make_shared<Style>();
//    std::dynamic_pointer_cast<Style>(style4)->modifier_attribut(attribut2);
//    c1["bloc"] = page_ptr->element(std::dynamic_pointer_cast<Constante>(c1.get("indice"))->valeur()-1, NoeudElement::Bloc_t::paragraphe);
//    std::dynamic_pointer_cast<BaliseStyle>(c1.get("bloc"))->style() = style4;

    // Exemple 6
    NoeudPtr texte1 = std::make_shared<Texte>("Un titre");
    NoeudPtr titre1 = std::make_shared<BaliseTitre>(texte1, std::make_shared<Style>(), 1);
    page_ptr->ajouter_element(titre1);
    NoeudPtr couleur1 = std::make_shared<Couleur>(std::make_shared<Texte>("#000000"));
    std::dynamic_pointer_cast<BaliseTitre>(page_ptr->element(std::make_shared<Constante>(0), NoeudElement::Bloc_t::titre1))->attribut(Attribut::Attribut_t::couleurFond) = couleur1;

    page_ptr->sauvegarder("../exemple_source/final.html", c1);
    return 0;
}

