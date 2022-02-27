#include <iostream>

#include "Cilindro.hh"
#include "Cubo.hh"
#include "Sfera.hh"
#include "Scatola.hh"

using namespace std;

int main() {

    Cilindro * cil = new Cilindro(10,20);
    Cubo * cub = new Cubo(12);
    Sfera * sfe = new Sfera(15);

    Scatola * sca = new Scatola();
    sca->aggiungi(cil);
    sca->aggiungi(cub);
    sca->aggiungi(sfe);

    double vt = sca->volumeTotale();
    double st = sca->superficieTotale();

    cout << "Volume totale : " << vt << endl;
    cout << "Superficie totale : " << st << endl;

    delete cil;
    delete cub;
    delete sfe;
    delete sca;

    return 0;
}

