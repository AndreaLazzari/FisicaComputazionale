#include <iostream>
using namespace std;

struct Verbose{
    
   
    Verbose(){ cout<< "CTOR" <<endl;}; 
    ~Verbose(){ cout<< "DTOR" <<endl; }; 
    
};


Verbose gimme(){     //una funzione restituisce un temporary
    
    //Verbose v;
    //return v;
    
    return Verbose();   //equivalente alle due righe sopra, chiama il costruttore, genera una variabile (senza nome) di tipo verbose e la restituisce al flusso del programma
};    //ATTENZIONE: se la funzione restituisse "Verbose &" (referenza) avrei un problema di lifetime
      //il main si troverebbe una referenza "dangling", cioè legata ad un oggetto defunto (fuori dallo scope della funzione)


int main(){
    
   //Verbose v = gimme();  //ok
   
   
   
  // Verbose & rv = gimme();  non posso, errore: cannot bind lvalue reference (Verbose&)  
                                                            //to a temporary/rvalue (Verbose)

  //lvalue ("left value") possono stare al membro sinistro di un =
  //rvalue ("right value") non possono stare al membro sinistro di un =  (non è detto che possano stare a destra di un = )
   
   int i;
   i = 4;   //ok
   //4 = i;   //uguale non commutativo, non simmetrico
              //4 è una costante di compilazione
    
   
   
 //object.funz è un rvalue
 
 
 //(i++) è un rvalue , (++i) è un lvalue
 //dammi il valore di i (non incrementato) e poi incrementalo di 1 --> i++
 //incrementa di 1 e dammi il valore di i (incrementato) --> ++i
          //(posso fare ++i=7)
   
   
 //non posso usare l'operatore & sugli rvalue ( &4 non ha senso)
 //non posso legare una referenza (non-const) a un rvalue
 
 
 //gimme() è un rvalue
 // &gimme(); // non posso



//un temporary è un oggetto anonimo automatico temporaneo
   gimme();    //in questa riga il temporary nasce e muore
   cout<< " ---- " <<endl;
    
           //temporary vengono generati:
           // - come valori di ritorno delle funzioni
           // - dalle chiamate esplicite al costruttore
           // - nelle conversioni automatiche dei tipi
   
    
};
