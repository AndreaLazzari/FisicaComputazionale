//std::map è il container "associativo" in senso stretto, cioè associa delle chiavi a dei valori
//la chiave è il ricercabile, il valore è ciò a cui ho accesso una volta che ho trovato la chiave
//ANALOGIA con DIZIONARIO : chiave (parola)   <--->  valore (definizione)


//la ricerca è O(log(N))
//
//map contiene associazioni singole, chiavi singole (la seconda è ignorata)

#include<map>
#include<string>
#include<iostream>

using namespace std;



int main(){
                                
                //map --> template < tipochiave, tipovalore >
                //std::map<key_type,value_type>
    
    std::map <int,string> m = { {1,"one"} , {1,"uno"} , {2,"two"} , {10, "ten"}, {3,"three"} };  
    
         //internamente gli oggetti contenuti in
         //map<int,string> sono pair<int,string>
         //contiene "coppie singole" e ordina gli elementi in base all'operatore "<" delle chiavi
    
    auto beg = (*m.begin());
    cout<< beg.first << "  " << beg.second <<endl;
    
    //operator []     
    cout<< m[3] <<endl;    //non devo pensare al terzo elemento della mappa!
                           //vuol dire 'l'elemento che ha chiave "3"'
                           //la chiave non deve necessariamente essere intera
    
    m[4]="four";   //l'operatore [] restituisce il valore relativo alla chiave se la chiave esiste,
            //altrimenti crea una nuova coppia chiave-valore e la inserisce nella collezione
    
    m[10]="dieci";  //posso ridefinire il valore di una chiave
    
    //(*m.begin().first = 99); // ERRORE: chiave NON modificabile (read only)
    
    cout << m[20] << "  " << m[10] <<endl;
    
    
};


//in std::set gli elementi sono const
//in std::map le chiavi sono const (i valori no)


//esistono multimap e unordered_map
