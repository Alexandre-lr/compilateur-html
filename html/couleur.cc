#include "couleur.hh"
#include "text.hh"

Couleur::Couleur(std::uint8_t const & r, std::uint8_t const & v, std::uint8_t const & b)
    : _r(r), _v(v), _b(b) {

}

Couleur::Couleur(NoeudPtr couleurHex) {
    auto text(std::dynamic_pointer_cast<Text>(couleurHex)->valeur());
    _r = static_cast<std::uint8_t>(std::stoi(text.substr(1, 2), nullptr, 16));
    _v = static_cast<std::uint8_t>(std::stoi(text.substr(3, 2), nullptr, 16));
    _b = static_cast<std::uint8_t>(std::stoi(text.substr(5, 2), nullptr, 16));
}

std::string Couleur::to_html(const Contexte & contexte) const {
    std::stringstream ss;
    ss << "#"
       << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(_r)
       << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(_v)
       << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(_b);

    return ss.str();
}
