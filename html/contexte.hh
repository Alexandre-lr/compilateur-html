#pragma once
#include <map>
#include <string>
#include "noeud.hh"

class Noeud;
using NoeudPtr = std::shared_ptr<Noeud>;
class Contexte {
private:
    std::map<std::string, NoeudPtr> variables;

public:
    Contexte() = default;
    Contexte(const Contexte& autre) = default;

    NoeudPtr& get(const std::string& nom);
    const NoeudPtr& get(const std::string& nom) const;

    NoeudPtr& operator[](const std::string& nom);
    const NoeudPtr& operator[](const std::string& nom) const;
};

