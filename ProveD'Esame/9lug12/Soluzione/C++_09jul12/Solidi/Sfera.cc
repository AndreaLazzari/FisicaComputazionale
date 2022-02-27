#include "Sfera.hh"
#include <cmath>

Sfera::Sfera(double r) : raggio(r) {
}

double Sfera::volume() {
    double v = 4.0/3.0 * M_PI * raggio * raggio * raggio;
    return v;
}

double Sfera::superficie() {
    double s = 4 * M_PI * raggio * raggio;
    return s;
}
