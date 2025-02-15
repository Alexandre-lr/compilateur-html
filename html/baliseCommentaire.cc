#include "baliseCommentaire.hh"

BaliseCommentaire::BaliseCommentaire(NoeudPtr texte)
    : NoeudElement(texte) {

}

std::string BaliseCommentaire::to_html(const Contexte & contexte) const {
    // Saute de ligne et tabulation faite dans la méthode regrouper_commentaires de la classe noeudCorps
    return "\t\t " + contenu()->to_html(contexte) + "\n";
}

NoeudElement::Bloc_t BaliseCommentaire::type_balise() const {
    return NoeudElement::Bloc_t::commentaire;
}
