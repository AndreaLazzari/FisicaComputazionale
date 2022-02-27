#include "Cubo.hh"
#include <cmath>

Cubo::Cubo(double l) : lato(l) {
}

double Cubo::volume() {
    double v = lato*lato*lato;
    return v;
}

double Cubo::superficie() {
    double s = lato*lato*6;
    return s;
}
