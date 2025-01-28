#include <iostream>
#include "page.hh"

Page::Page(NoeudPtr corps, NoeudPtr entete)
    : _corps(corps), _entete(entete) {

}

std::string Page::to_html(const Contexte & contexte) const {
    std::string corps(_corps->to_html(contexte));
    std::string entete(_entete->to_html(contexte));
    std::string page("<!DOCTYPE html>\n");
    page += entete;
    page += corps;
    page += "</html>";

    return page;
}

void Page::sauvegarder(const std::string & dest, const Contexte & contexte) const {
    std::ofstream fichier(dest);

    if (fichier.is_open()) {
            fichier << this->to_html(contexte);
            fichier.close();
            std::cout << "Fichier sauvegardé avec succès : " << dest << std::endl;
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier " << dest << " !" << std::endl;
        }
}
