#include "Scatola.hh"

Scatola::Scatola() {
    dimensioni = 0;
}

void Scatola::aggiungi(Solido * s) {
    solidi[dimensioni] = s;
    dimensioni++;
}

double Scatola::volumeTotale() {
    double v = 0;
    for ( int i=0;i<dimensioni;i++) {
        v+=solidi[i]->volume();
    }
    return v;
}

double Scatola::superficieTotale() {
    double s = 0;
    for ( int i=0;i<dimensioni;i++) {
        s += solidi[i]->superficie();
    }
    return s;
}
