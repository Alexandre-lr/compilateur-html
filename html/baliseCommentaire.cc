#include "baliseCommentaire.hh"

BaliseCommentaire::BaliseCommentaire(NoeudPtr text)
    : NoeudElement(text) {

}

std::string BaliseCommentaire::to_html(const Contexte & contexte) const {
    return "<!--" + contenu()->to_html(contexte) + "-->";
}

// Seul balise sans nom
std::string BaliseCommentaire::nom_balise() const {
    return "";
}
