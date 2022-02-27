#include <iostream>
using namespace std;

//le referenze sono di un tipo diverso rispetto alla variabile a cui si riferiscono
//l'indirizzo della referenza è lo stesso indirizzo della variabile a cui si riferisce


void f(int & loc){};



int main (){

 int i;
 f(i);     //il tipo dell'argomento (i) e il tipo del parametro (loc) sono diversi



                    //cosa succede a prendere l'indirizzo di una ref?
 int & ri = i;   
 &ri;               //POSSO: una referenza è un lvalue
                    //(questo vale anche per le rvalue ref)

 cout<< &ri << " " << &i << endl;

};
