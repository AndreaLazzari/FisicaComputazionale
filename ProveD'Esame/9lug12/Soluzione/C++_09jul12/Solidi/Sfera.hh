#ifndef SFERA_HH
#define SFERA_HH

#include "Solido.hh"

class Sfera : public Solido {
public:
    Sfera(double r);
    virtual double volume();
    virtual double superficie();
private:
    double raggio;
};

#endif // SFERA_HH
