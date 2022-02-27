#ifndef CILINDRO_HH
#define CILINDRO_HH

#include "Solido.hh"

class Cilindro : public Solido {
public:
    Cilindro(double r, double h);
    virtual double volume();
    virtual double superficie();
private:
    double altezza;
    double raggio;
};

#endif // CILINDRO_HH
