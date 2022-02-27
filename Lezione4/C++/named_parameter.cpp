//Scrivere una struct/class Widget tale che il seguente main:
//stampi su cout 3,2,2


#include <iostream>
using namespace std;

struct Widget{
    
private:  
    int val;
    
public:   
    Widget & set(int v){ val = v;
                        return *this; };    //return *this dell'oggetto che ha fatto la chiamata
                       
    Widget & print() { cout << val <<endl ;
                       return *this ;  };

};


int main(){
    
    Widget w; //Widget vuol dire "apparecchio"
    
    w.set(3).print().set(2).print();     //operatore "." è associativo a sinistra
    w.print();          
                                   //semantica di valore VS semantica di referenza
                    //referenza oggetto passato fisicamente dal main alle funzioni o dalle funzioni al main
    
};

/*
 
 
     //da main a funzione
     
void funz(T arg){
};

  funz(expr);      //---> arg(expr)   arg viene costruito a partire da expr



     //da funzione a main

T funz(){
   return expr;         //l'oggetto di tipo T viene inizializzato con expr
};

*/

