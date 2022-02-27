#ifndef CUBO_HH
#define CUBO_HH

#include "Solido.hh"

class Cubo : public Solido
{
public:
    Cubo(double l);
    virtual double volume();
    virtual double superficie();
private:
    double lato;

};

#endif // CUBO_HH
