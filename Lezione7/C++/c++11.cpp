#include <iostream>
using namespace std;



//C++ 11:


// - auto: deduzione automatica dei tipi
// - initializer list (uniform initialization)
// - range-based for loops



//auto non può essere usato per dedurre i tipi di parametri di funzione
//[si può fare con i template o con le lambda]
complex somma(auto c1, auto c2) {...}



int main(){
    
    auto i = 0;
  //  auto var = funz();   //disaccoppiamento, disaccoppia ciò che è fatto nel main da ciò che è scritto nella
                           // libreria contenente la funzione (ad esempio viene gestito automaticamente 
                           // il cambio di tipi)
    
    int & ri = i;
    auto var = ri;   //ATTENZIONE: var è un int, non int&
    
    //per controllare    
    //var = 5;
    //return i;   //ritorna 0, var non modifica il valore di i
    
    auto & ref = i; //forza a dedurre una referenza
    
    
    //initializer list:
    
    int arr[5] = {3,3,0,1,2};
    
    
    //range-based for:
         
    for (auto i : arr){ /*  */};
    
    for  (auto & i : arr){
        i=10;                    //questo cambiamento è locale, alla fine del for "perde valore"
                                 //con "auto & i " il cambiamento non è a valore ma a referenza 
                                 //vive anche oltre al for
    } ;
    
     for (int i : arr){ cout << i <<endl;}  //stampa gli elementi di arr ciclando su i
    
};

