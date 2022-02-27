//STL: Standard Template Library (generica)
//strutture dati ---> containers / iteratori / algoritmi / funzioni 


//CONTAINERS: collezioni di oggetti omogenee (stesso tipo)

//1) sequenziali  (gli oggetti hanno una sequenza modificabile, cioè sequanze diverse 
//                                             sono stati diversi della struttura dati)
//                                                    
//          a)dinamici: vector, deque, list, forward_list (adattano la taglia in runtime)
//          b)statici: array  (NON adattano la taglia in runtime)


//2) associativi ( = non sequenziali)



#include <vector>
#include <iostream>
using namespace std;

int main(){
    
    //vector tiene gli elementi *consecutivamente* in memoria
    //Istantaneamente vector ha una "capacità", cioè una zona di memoria
    //che in quel momento si è riservato. Se viene aggiunto un elemento in più 
    //della capacità (ad esempio con il metodo push_back), avviene una riallocazione dei dati:
    //viene allocata una zona di memoria (moltiplicativamente) più grande, 
    //vi vengono copiati gli elementi vecchi, e poi aggiunto l'ultimo
    
    
    vector<int> v= {3,1,6,77,-3};
    
    //c'è un overloading di operator[]   (gli elementi partono dal consueto 0), 
    //restituisce una referenza &, posso scriverci
    v[2]=0;
    cout<<v[2]<<endl;
    
    v.push_back(1);   //argomento dello stesso tipo degli elementi del vector, 
                        //aumenta la taglia di un posto e ci inserisce 1
                        //richiede un tempo O(1), cioè non dipende dalla size
                        //push_front richiederebbe un O(size)
                        
                        
        //deque (double ended queue) ha anche push_front                
    
    
                       //un vector non inizializzato è *vuoto*
    vector<double> w;  //non posso fare w[2]
    
    
    
    
    
    
};



//performance: il layout di vector (memoria contigua) minimizza i "cache miss"

//list è utile per fare l'operazione "splice"


