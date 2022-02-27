#include "Cilindro.hh"
#include <cmath>

Cilindro::Cilindro(double r, double h) : altezza(h),raggio(r) {

}
double Cilindro::volume() {
    double v = M_PI * raggio * raggio * altezza;
    return v;
}

double Cilindro::superficie() {
    double s = M_PI * raggio * raggio * 2 + 2 * M_PI * raggio * altezza;
    return s;
}
