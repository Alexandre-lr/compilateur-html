#include "baliseTextuel.hh"

BaliseTextuel::BaliseTextuel(NoeudPtr text)
    : _text(text) {

}

NoeudPtr BaliseTextuel::text() const {
    return _text;
}
