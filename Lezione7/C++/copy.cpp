#include <iostream>
using namespace std;

struct Verbose{
    
     Verbose(){ cout<< "CTOR" <<endl;}; 
    ~Verbose(){ cout<< "DTOR" <<endl; }; 
     Verbose (const Verbose &){cout << "COPY" <<endl; };     //costruttore di copie
    
};


Verbose gimme(){   
    
    //Verbose v;
    //return v;      // NRVO
    
    return Verbose();        //[N]RVO [Named](Return Value Optimization) oggetto costruito dove serve
};


void by_val(Verbose locale){};

int main(){
    
    /*
   //Verbose & rv = gimme();  //no, non può legarsi ad un temporary    
   
   const Verbose & rv = gimme();   //una referenza costante può legarsi ad un temporary
                                   //quando una const reference si lega ad un temporary
                                   //il tempo di vita del temporary si estende a quello della reference
   
   cout<< "  ---- " <<endl;
    
   */
    
    
    //Verbose v;
    //by_val(v);   // ho due DTOR, viene inizializzato un nuovo Verbose che non utilizza il costruttore normale
                   // bensì il "costruttore di copie", il nuovo Verbose è costruito a partire da una copia
    
   // Verbose w(v);   //chiamata esplicita del copy CTOR
   
   
    Verbose w(gimme());
    

    
};


//Copy elision: è un' *ottimizzazione* (che il compilatore può fare) in cui
//è permesso al compilatore di elidere le copie, cioè di eliminare le copie "inutili" 



