#include "baliseCommentaire.hh"

BaliseCommentaire::BaliseCommentaire(NoeudPtr text)
    : NoeudElement(text) {

}

std::string BaliseCommentaire::to_html(const Contexte & contexte) const {
    // Saute de ligne et tabulation faite dans la méthode regrouper_commentaires de la classe noeudCorps
    return "<!--" + contenu()->to_html(contexte) + "-->\n";
}

// Seul balise sans nom
std::string BaliseCommentaire::nom_balise() const {
    return "";
}
