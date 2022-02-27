#include <iostream>
using namespace std;


struct Verbose{
    
    int i,k;
    
    //costruttore di default, cioè senza parametri
    Verbose(){ cout<< "CTOR" <<endl;}; //costruttore: come nome il nome della classe, non ha tipo di ritorno
    
    //il costruttore può avere prametri
    
    // Verbose(int j) { i = j; };
    
     /*explicit*/ Verbose(int j1, int j2 = 0) : i(j1) , k(j2) { cout << "CTOR LISTA I"<<endl;};   //lista di inizializzazione [per i tipi integrati la sintassi i(j1) è detta dello pseudo-costruttore]  (int j2=0 significa che se viene passato un parametro in meno rispetto ai due richiesti, l'altro va automaticamente a 0) [se "fisso a 0" anche il primo ho triplo costruttore: 0 parametri, ad 1 parametro e a 2 parametri]
    
    ~Verbose(){ cout<< "DTOR" <<endl; }; //distruttore: come nome tilde~ più nome della classe, non ha tipo di ritorno
    
    //il distruttore NON può prendere parametri
    //NON è MAI necessario chiamare esplicitamente il distruttore (non si può), all'uscita dello scope, una variabile automatica viene automaticamente distrutta
    //per una variabile dinamica si ha new e delete
    
};


void funz(Verbose ){};

//Valori di default (si riempiono da destra, altrimenti ho ambiguità)
void g(int i1 , int i, int i3 = 3 , int i4 = 0);


int main(){
    
  //Verbose v(4,8);      //ho chiamato Verbose(int , int )
   
   //new e delete chiamano automaticamente CTOR e DTOR
   //Verbose * pv = new Verbose;
   //delete(pv);
   
   
  // Verbose w(); //attenzione questo è una dichiarazione di una funzione ("most vexing parse")
   
   
   Verbose v(3);
   funz(7);  //mi aspetto un errore, funz ha come argomento una variabile di tipo Verbose; Automatic Type Conversion, effettuata perchè esiste un costruttore che ha come parametro un intero e genera un Verbose.
   //avviene attraverso il costruttore Verbose(int ) [in questo caso la lista di inizializzazione]
   //se metto "explicit" davanti al costruttore non viene fatta la conversione automatica   
   

   
};
