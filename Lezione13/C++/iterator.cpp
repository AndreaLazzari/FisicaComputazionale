//Gli iteratori estendono il concetto di puntatore
//alcuni container della STL non sono contigui in memoria, 
//ergo l'aritmetica dei puntatori non sarebbe rispettata;
//proprio per questo si utilizzano gli iteratori, in modo da disaccoppiare dalla struttura dati
//di diversi tipi in base alle funzioni che sono permesse (Random Acces, Bidirectional, Forward...)


#include<vector>
#include<array>
#include<iostream>

using namespace std;




int main(){
    
    vector <int> v = {2,3,5,8};
    
    auto iter = v.begin();  //begin restituisce un iteratore al primo elemento
         //end()  //restituisce un iter *dopo* l'ultimo elemento
         //[ da non deferenziare! ]
    
    
    cout<< *iter <<endl; 
    iter+=3;     //aritmetica degli iteratori
                 //ATTENZIONE: l'iteratore non controlla i boundary
    cout<< *iter <<endl;
    
    
    
    vector<int>::value_type num;   //num è di tipo int
    
    vector<int>::iterator iter2 = v.begin() +2;  //con auto, il compilatore deduce automaticamente
    
    
    array<int,5>::iterator iter3;  //iter3 è un iteratore in un array di 5 int
                                   //non è inizializzato a nulla, non sta "puntando" a nulla
    
    
    //l'operatore * restituisce una referenza (posso utilizzare la deferenziazione per scrivere)
    
    //c'è un overloading di -> (iter->membro)
    
    *iter=111;
    cout<< *iter << "   " << v[3]<<endl;
    
    
    cout<<endl<<endl;
                            //insert(posizioneDoveInserire, cosaInserire)
    v.insert(iter2, 10);    //inserisce 10 alla terza posizione di v
                            // ( iter2 = v.begin()+2 ) 
    
    for (auto elem: v){ cout << elem <<endl;};
    
    

    
    //nel caso del vector, grazie al layout consecutivo in memoria,
    // " iter + n " (spostarlo di n posti) è un'operazione che richiede O(1)
    // per una struttura dati (non sequenziali ad esempio list) questa operazione
    // NON è O(1) e quindi NON è ESPOSTA nell'interfaccia, non vale fare "iter + n"
    
    //[ vector<>::iterator è della categoria "Random Access"
    // list::iterator  è "Bidirectional" ]
    
    
    
    //*ATTENZIONE*: alcune operazioni sui container (ad esempio insert su un vector)
    //     lasciano alcuni iteratori in uno stato invalido,
    //     cioè leggerli o scriverli da' undefined behaviour
    // certe operazioni portano a ---> "invalidazione degli iteratori"
    // ( l'iteratore come variabile automatica rimane valido: posso ad esempio riassegnarlo )
    
    //I Random Access contemplano :
    // - il confronto < , >  proprio perchè è definito un "prima" ed un "dopo";
    //per tutti i tipi di iteratori è valido il confronto == , != ;
    
      
    vector<int>::iterator it1;
    vector<double>::iterator it2;
    //it1==it2; //NON posso: it1 e it2 sono di tipi diversi!
    
    
    
    //per i Random Access posso calcolare la "posizione" di un elemento
    //con due iteratori che si riferiscono alla stessa collezione di elementi
    
   //es. it1 - v.begin();
    

    
};




  
 double ProdScal(vector <double> , vector <double> );
 double ProdScal(vector <double>  a , vector <double> b){
     
     double sum = 0;
     
    for (int i = 1; i <= a.size() ; i++){
       
       sum += a[i]* b[i];      
    
    };
     return sum;
 };

