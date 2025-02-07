#include "noeudEnTete.hh"
#include "propriete.hh"

std::string NoeudEnTete::to_html(const Contexte & contexte) const {
    std::string head(_proprietes.at(Propriete_t::langue)->to_html(contexte));
    head += "\t<head>\n";
    for (auto const & propriete : _proprietes)
        if (propriete.first != Propriete_t::langue)
            head += propriete.second->to_html(contexte);
    head += "\t\t<title>" + _titre->to_html(contexte) + "</title>\n";
    head += "\t</head>\n";

    return head;
}

const NoeudPtr & NoeudEnTete::langue() const {
    return _proprietes.at(Propriete_t::langue);
}

void NoeudEnTete::modifier_propriete(NoeudPtr propriete) {
    auto ptype(std::dynamic_pointer_cast<Propriete>(propriete)->type());

    auto it(_proprietes.find(ptype));
    if (it != _proprietes.end())
        it->second = propriete;
    else
        _proprietes[ptype] = propriete;
}

void NoeudEnTete::modifier_titre(NoeudPtr titre) {
    _titre = titre;
}
