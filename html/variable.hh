#pragma once
#include <string>
#include "noeud.hh"



class Variable : public Noeud
{
public:
    Variable() = delete;
    Variable(const Variable &) = default;
    Variable(const std::string & nom);
    
    std::string toHTML(const Contexte & contexte) const override;
private:
    std::string _nom;
};
