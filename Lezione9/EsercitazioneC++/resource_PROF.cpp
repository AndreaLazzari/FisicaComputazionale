// - Una classe Resource che contenga un puntatore ad una zona allocata
// dinamicamente e riempita di valori, da inizializzare nel costruttore 
// (ad es. tutti uguali)
// - Resource deve occuparsi anche di deallocare nel distruttore [ownership]
// - Scrivere: a) copy-constructor (semantica di valore)
//             b) una funzione move (semantica di spostamento) [efficiente]
//	       b1) move-constructor
//             c) una funzione swap (semantica di spostamento) [efficiente]


// Due oggetti "a" e "b" ognuno col suo puntatore "p", che punta alla
// zona di memoria dove l'oggetto ha allocato la risorsa durante la costruzione.
// a) Dopo una costruzione di copia Resource(b) 
//    le zone di memoria possedute da a e da b
//    contengano gli stessi dati: vanno copiati i dati.
// b) Dopo una chiamata a move(a,b) ( a -> b )
//    il puntatore b.p punti alla zona di memoria
//    che prima apparteneva ad a: non vanno copiati i dati.
//    L'oggetto a perde la ownership della risorsa.
//    Vanno dunque fatte altre due operazioni:
//    (i) liberare la memoria posseduta da b (altrimenti nessun altro oggetto se ne occupera')
//    (ii) invalidare l'oggetto a, a cui la risorsa e' stata "rubata"
//         (ad es si puo' fare questo assegnando il puntatore a NULL o nullptr [c++11];
//          nel codice qui sotto invece usiamo un flag is_valid)
// b1) Il costruttore per spostamento (move constructor) fa le stesse cose della funzione move;
//     la differenza e' che viene chiamato in *costruzione*, dunque non deve liberare
//     la memoria gestita dall'oggetto che "ruba" la risorsa (oggetto che non e' ancora costruito)
// c) Dopo una chiamata a swap(a,b) i due puntatori a.p e b.p
//    si sono scambiati (nessuno perde ownership: se la scambiano)

// NOTA: per scrivere in modo compatto e corretto gli operatori = (sia per copia che per spostamento)
//       vedi "copy-swap idiom" (qui non implementato)



#include <cstdlib>
#include <iostream>
#include <cstring> // per memcpy
#include <cmath>
using namespace std;

using data_t = char; // type alias (usa "data_t" per dire "char")


template < int N >
class Resource {
  data_t * mem_;
  bool is_valid;

  // helper function che fa deep copy (si puo' fare anche con un ciclo)
  void copy_(const Resource & n) {
    memcpy( mem_, n.mem_, N*sizeof(data_t) );
  }
public:
  // il costruttore alloca la risorsa con new e la riempie
  Resource() : is_valid(true) {
    mem_ = new data_t[N];
    for (int i = 0; i<N; ++i) mem_[i] = 65+(rand()%26);
  }
  // il distruttore libera la risorsa con delete
  ~Resource() {
    if (is_valid) delete [] mem_;
  }
  
  // DEEP COPY (viene copiata tutta la memoria puntata da mem_)
  Resource(const Resource & n) {
    is_valid = false;
    if (n.is_valid) {
      mem_ = new data_t[N];
      is_valid = true;
      copy_(n);
    }
  }

  // MOVE (viene copiato solo il puntatore, e invalidato l'oggetto sorgente)
  // Attenzione: questo codice non controlla il caso del self-assignment tipo a.move(a)
  void move(Resource & n) {
    if (n.is_valid) {
      if (is_valid) delete [] mem_;
      mem_ = n.mem_;
      n.is_valid = false;
      is_valid = true;
    }
  }

  // MOVE CTOR
  Resource(Resource && n) : is_valid(false) {
    if (n.is_valid) {
      mem_ = n.mem_;
      n.is_valid = false;
      is_valid = true;
    }
  }

  // SWAP (volendo c'e' un template di funzione nella STL)
  void swap(Resource & n) {
    data_t * tmp_d = mem_;
    bool tmp_s = is_valid;
    mem_ = n.mem_;
    is_valid = n.is_valid;
    n.mem_ = tmp_d;
    n.is_valid = tmp_s;
  }

  void print(ostream & os) {
    if (is_valid)
      for (int i=0; i<N; ++i) os << mem_[i];
    else
      os << "Oggetto non valido";
    os << endl;
  }
};


int main() {

  srand48(time(NULL));

  Resource<6> A; 
  Resource<6> B;
  // nota: con interi diversi sarebbero *tipi diversi*

  cout << endl << "A: "; A.print(cout);
  cout << "B: "; B.print(cout);
  cout << endl;

  A.move(B); // spostamento

  cout << "A: "; A.print(cout);
  cout << "B: "; B.print(cout);
  cout << endl;

  B.move(A); // spostamento verso un oggetto non valido

  cout << "A: "; A.print(cout);
  cout << "B: "; B.print(cout);
  cout << endl;

  A.swap(B); // scambio di un oggetto valido e uno invalido

  cout << "A: "; A.print(cout);
  cout << "B: "; B.print(cout);
  cout << endl;

  Resource<6> C(std::move(A)); // costruzione per spostamento
  
  cout << "A: "; A.print(cout);
  cout << "C: "; C.print(cout);
  cout << endl;


  Resource<6> D(std::move(A)); // costruzione per spostamento da un oggetto non valido
  
  cout << "A: "; A.print(cout);
  cout << "D: "; D.print(cout);
  cout << endl;
  
}
