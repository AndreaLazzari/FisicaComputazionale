//Algoritmi

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;



bool predicato(int lhs, int rhs){ return lhs > rhs; };

int main(){
    
    vector<int> v = {5,2,2,8,5,7,3,3,2};
    cout<<"First : " <<endl;
    for (int i:v){ cout << i <<endl; };
    
    cout<<endl<<endl;
    
    std::sort( v.begin() , v.end() );
    //NOTA: std::sort ordina gli elementi compresi tra il primo iteratore (compreso) e il secndo (escluso!)
    //[ in generale il range tra it1 e it2 è [ it1 , it2 )
    
    for (int i:v){ cout << i <<endl; };
    
    //--> std::sort vuole iteratori random access
    
    
    
    //remove
    //Fa in modo che gli oggetti *diversi* da quello dato
    //vadano a trovarsi in *testa* alla collezione
    //non adatta la taglia del vettore, se toglie tre elementi, gli ultimi tre dopo il remove saranno "spazzatura"
    //e restituisce un iteratore che punta al primo elemento "spazzatura"
    
    /*std::remove( v.begin(), v.end() , 2);
    //v.erase(it1,it2) rimuove tutti gli elementi in [it1,it2) e ridimensiona la collezione 
    cout<<"Then with garbage: " <<endl;
    for (int i:v){ cout << i <<endl; };*/
    
    
    // ---> erase-remove idiom
    v.erase( remove( v.begin(), v.end(), 2) , v.end() );
    
    cout<<"Then final: " <<endl;
    for (int i:v){ cout << i <<endl; };
    
    cout<<endl<<endl;
    
    
  //std::sort ha un terzo parametro opzionale, che è un predicato binario che implementa il criterio di confronto
  // - un predicato è una funzione che restituisca BOOL (no side effect, non possono modificare lo stato della memoria)
  // - un predicato binario è un predicato che prende due argomenti
    
    
  std::sort( v.begin() , v.end() , predicato );
  cout<<"Sorted with predicato: " <<endl;
  for (int i:v){ cout<< i <<endl;};
    
    
    
    
    
};
