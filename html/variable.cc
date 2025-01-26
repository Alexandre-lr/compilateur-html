#include "variable.hh"

Variable::Variable(const std::string& nom)
    : _nom(nom) {

}

std::string Variable::toHTML(const Contexte & contexte) const {
    return contexte[_nom]->toHTML(contexte);
}
