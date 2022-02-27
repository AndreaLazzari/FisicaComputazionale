#include<iostream>
using namespace std;

//astrarre il concetto di "coppia"


// "template" significa "stampo , prototipo"
// -> un template è un prototipo per costruire *tipi*




//class template                                  //se viene passato solo un tipo, il secondo sarà int/T
template < typename T , typename U = int/*T*/>   //NON c'è ";" si applica solo a ciò che lo segue strettamente    
struct myPair {
    T t;
    U u;
    
    void set(T tt, U uu) {
        t = tt;
        u = uu;
    };
    
    T get_t(){ return t;};
    U get_u(){ return u;};
    
};

//[esiste la "specializzazione" dei template]



struct A{};


//[[in c++20 saranno aggiunti i "concept"]]



//function template
template < typename T >
void print(T t){
    cout<< " ( " << t << " ) "<<endl;
};




//i parametri dei template possono essere anche valori (interi) oltre al poter essere tipi
//"non-type parameters"

template <typename T, int i>
void f(T t) { /*    */};






int main(){
    
  myPair < int , int > p; //p è un oggetto di tipo "myPair<int,int>"
    
  p.set(2,3);
  cout<< p.get_u()<<endl;
  
 // myPair q; //ERRORE: myPair NON è un nome di *tipo*: è un template 

  
  string s("n");
  int n(3);
  
  
  print<string>(s);
  print<int>(n);
  print(A()); //ERRORE: non esiste l'overload per l'operatore "<<" preposto ad una struct
  
  print (s); //Automatic Type Deduction (non ho specificato <string>)
  
  myPair < double > p;  //il tipo di default per il secondo è int (definito sopra)
 
  myPair <double, string > f;
  
  //p=f;//ERRORE: p ed f sono di due tipi diversi
  //            myPair<int,int>   myPair<double,string>
 
 
  
  f<double , 3>(0.);  //in qualche modo riesco ad anticipare in compile-time calcoli/controlli
  
  
  
 
};


//un template è una funzione che prende come argomento dei tipi
//e restituisce un tipo (una funzione che viene eseguita in compile time)
//---> meta-programming (insegnare al compilatore a eseguire
//                         meta-programmi in compile-time)
