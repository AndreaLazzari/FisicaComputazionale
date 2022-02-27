#include <iostream>
using namespace std;

//se ho un oggetto che gestisce una risorsa (es. scrittura esclusiva su una periferica)
//diventa rilevante la distinzione tra
//semantica di copia e di spostamento
// ---> posso copiare l'oggetto o "rubare" la risorsa



struct Verbose {
    
     Verbose(){ cout<< "CTOR" <<endl;}; 
    ~Verbose(){ cout<< "DTOR" <<endl; }; 
     Verbose(const Verbose &){cout << "COPY" <<endl; };    //copy CTOR
     Verbose(Verbose &&) {cout << "MOVE" <<endl; };   //move CTOR
         //il move CTOR vine chiamato quando viene fatta una "copia" di un temporary
};


Verbose gimme(){   
    
    return Verbose();       
    
};


void by_val(Verbose){};
void by_ref(const Verbose &){ cout << "lvalue" <<endl;};
void by_ref(Verbose &&){ cout << "rvalue" <<endl;};


int main(){
    
  
    const Verbose & rv = gimme();    //funziona prolungando la vita del temporary
                                     //rv referenza a lvalue
    
    
    
    //una referenza a rvalue si lega esclusivamente agli rvalue
    Verbose && rrv = gimme();
    // 1) non è const --> posso accederci con membri non constanti e scrivere
    // 2) non può legarsi a lvalue
   /*   Punto2)
    Verbose v;    //chiaramente lvalue
    Verbose && rrv2 = v;   //ERRORE: cannot bind &&ref to lvalue
   */
    
   
   //by_ref(gimme());   //non funziona senza overload set (se differenzio by_ref e by_rref), 
                        //non posso legare una referenza non const ad un temporary
   
   Verbose v;
   
   by_ref(v);
   by_ref(gimme());       //l'ambiguità tra by_ref(const Verbose &)
                          //e by_ref(Verbose &&) viene risolta in favore di quest'ultima
   
   by_ref(rv);   //LVALUE
   by_ref(rrv);  //LVALUE di nuovo! Perchè un rval ref è un lvalue
   
   
   
   by_val(gimme());    // -fno-elide-constructors per vedere MOVE
   
   
    
};

