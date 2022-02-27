//CONTAINER ASSOCIATIVI ( == NON SEQUENZIALI )
//la ricerca al loro interno richiede un tempo O(log(N)) o addirittura meno (in media)
//(la struttura dati tipicamente è un "self-balancing binary tree")


//std::set contiene una collezione di copie *singole* di oggetti (tutti oggetti diversi)
#include<set>
#include<iostream>

using namespace std;



struct Widget {
    
    int i;
    Widget(int i): i(i){};
    // < soddifa "strict weak ordering"
    bool operator<( Widget rhs ) const { return i < rhs.i; };  //lhs < rhs
                        //questo const specifica che la funzione non modifica il membro di sinistra
                        //posso scrivere &, && al posto di const, identificando quali tipi
                        //possono chiamare la funzione
};



int main(){
  
    
    std::set<int> s={2,4,10,6,5,7,2,5};   //template, <tipodioggetti>
    
    std::set<Widget> sw;
    Widget w(9);
    sw.insert(w);  //inizialmente ERRORE: al compilatore manca il confronto per l'ordinamento
                   // WORK post overload dell'operatore " < "
    
    for(int i:s){cout<< i <<endl;};  //stampando, se ci sono copie di qualche elemento,
                                     // non vengono stampate; la stampa degli elementi è in ordine crescente
                                     
                                     
                                     
  //Due oggetti "a" e "b" sono equivalenti in un container associativo
  //se ( !(a<b) && !(b<a))  (se non vero che a<b e non vero che b<a)
     
                                     
    
  /* for (auto it=s.begin(); it!=s.end(); ++it){
        cout<< *it<<endl;
    };   //stessa stampa con gli iteratori  */
      
      
      
  // begin() di un set "punta" sempre all'elemento più piccolo
  //(end()-1) di un set "punta" sempre all'elemento più grande 
    
  
  s.insert(-6);   //insert(cosainserire), l'ordine non è sotto il nostro controllo
                  //ma lo controlla il compilatore
  
  cout<< *s.begin() << "  " << *(++s.begin()) <<endl;
    
    
  cout<< s.count(2) << "  " << s.count(999) << endl;  
     
     //count(elemento): conto quante volte nella collezione sono presenti l'elemento 2 e l'elemento 999
     //chiaramente il risultato è sempre 1 (presente) o 0 (non presente)
     //perchè ogni elemento può essere presente al massimo una volta
       
    
};


  // - c'è una versione di set che tiene anche elementi multipli: multiset
  // - c'è una versione di set in cui la ricerca è 0(1): unordered_set
  //   ( è implementato in termini di hash tables )
