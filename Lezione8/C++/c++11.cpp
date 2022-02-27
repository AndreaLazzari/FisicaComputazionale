//(...continued) C++11
// - decltype


#include <iostream>
using namespace std;

  
//se avessi ad esempio la definizione di tipo di ritorno all'interno di una libreria esterna
//auto e decltype settano automaticamente il tipo della funzione
//"trailing type" (omissibile in c++14)

auto f(Widget w1 , Widget w2) -> decltype(w1+w2) {
    
    return w1+w2;
    
};


auto f(int i, int j) -> int {
    return i-j;
};


//C++14:
auto g(int i){
    return i;
};



//C++14
 decltype(auto) h(int i) {       //deduce automaticamente il tipo di ritorno usando le regole di deduzione 
                                 //di decltype che "vedono" le referenze
    return ;
 };


int main(){
    
  int i=0;
  int & ri = i;
  auto x = ri;   //il tipo di x è un int , ad auto non importano le referenze
  
  // decltype sostituisce il tipo della var i, importandosene delle referenze
  decltype(i) y;         // " il tipo di y è il tipo di i "
  decltype(ri) z = i;    //z è una referenza    
    
  z=4;
  cout << i <<endl;      //i cambia valore avendo agito con la referenza 
    
    
    
};
