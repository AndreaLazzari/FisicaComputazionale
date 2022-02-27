#include <iostream>
using namespace std;

void incr(int k){    //k variabile locale
  ++k;
}


void incr(int *p){
  ++(*p);

}    

int main(){

    int i = 5; double d = 3.14;
    
    std::cout << &i << " " << &d << " " <<endl;   
    // :: è l'operatore di risoluzione dello scope, dei nomi
    
    //un puntatore è una variabile contenente l'indirizzo di memoria di una data variabile
    
    int *pi;   //definisce un "puntatore a int"
    pi = &i;   //l'operatore & è "address-of" [modifico pi]

    //pi = &d;    //errore (c++ linguaggio fortemente tipizzato int <-> double )
    
    //*pi è l'intero che siede all'indirizzo puntato da pi
    // "*" è l'operatore di deferenziazione
    
    *pi = 7;    //scrivo attraverso "pi"   [modifico i]
    cout << i << " " << *pi << endl;    //leggo "i"
    
    //---> il puntatore è un "alias" della variabile, agendo con *pi è uguale ad agire con i (accedo alla stessa variabile con due nomi diversi)
   
    
    incr(i);  
    cout << i <<endl;   //i non si incrementa (cambia solo k locale della funzione)
    
    incr(pi);         //stesso effetto con incr(&i)
    cout<<i<< endl;    //qui i si incrementa perchè agisco sul contenuto dell'area di memoria di i puntata da pi 
    
    
    
    
    
    
    
};
