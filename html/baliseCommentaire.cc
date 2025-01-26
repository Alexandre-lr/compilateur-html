#include "baliseCommentaire.hh"

BaliseCommentaire::BaliseCommentaire(NoeudPtr text)
    : NoeudElement(text) {

}

std::string BaliseCommentaire::toHTML(const Contexte & contexte) const {
    return "<!--" + contenu()->toHTML(contexte) + "-->";
}

// Seul balise sans nom
std::string BaliseCommentaire::nomBalise() const {
    return "";
}
