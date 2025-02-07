#ifndef DRIVER_H
#define DRIVER_H

#include <string>

#include "contexte.hh"

class Driver {
private:
    Contexte variables;       
public:
    Driver();
    ~Driver();
     
    const Contexte& getContexte() const;
    NoeudPtr&  getVariable(const std::string& name);
    void setVariable(const std::string& name, NoeudPtr& value);
};

#endif
