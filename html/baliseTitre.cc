#include "baliseTitre.hh"

BaliseTitre::BaliseTitre(NoeudPtr text, NoeudPtr style, const std::uint8_t & niveau)
    : BaliseStyle(text, style), _niveau(niveau) {

}

std::string BaliseTitre::nom_balise() const {
    return "h" + std::to_string(_niveau);
}
