#ifndef SCATOLA_HH
#define SCATOLA_HH

#include "Solido.hh"

class Scatola {
public:
    Scatola();
    void aggiungi(Solido *);
    double volumeTotale();
    double superficieTotale();
private:
    Solido * solidi[100];
    int dimensioni;
};

#endif // SCATOLA_HH
