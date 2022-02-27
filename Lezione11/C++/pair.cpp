#include<utility>
#include<typeinfo>
#include<tuple>
#include<iostream>


int main(){
    
    std::pair<int,int> p = {4,-1};    //template pair contenuto nella stdlib
    
    
    
    auto l = {1,2,3};  //è di tipo std::initializer_list
    std::cout<< typeid(l).name()<<std::endl;
    
    
    //si accede direttamente ai campi con fist e second
    std::cout<< p.first << "    " << p.second <<std::endl;
    
    //pair posso inizializzarlo con referenze
    
    int i = 3, j = 0;
    std::pair<int & ,int & > q(i,j);
    q.first = -12;
    
    std::cout<< i <<std::endl;
    
    
    //helper function template che attiva la deduzione automatica dei tipi a partire dagli elementi da cui è inizializzato
    
    auto r = std::make_pair(3.,4);  // è di tipo pairIdiE (di = <double,int>  , ii = <int,int>
    std::cout<< typeid(r).name()<<std::endl;   
    
    
    //collezioni di un numero arbitrario di oggetti eterogenei
    
    std::tuple<int,int,double> t = {1,0,9.9};
        
    //per accedere agli elementi della tupla [3 elementi: <0,1,2>] : 
    //esiste template di funzione get che prende un parametro intero
    
    std::get<2>(t)= 3.14;    
    std::cout<< std::get<2>(t)<<std::endl;
    //get restituisce una referenza, quindi può essere usato in scrittura
    
    //in c++14 è stata introdotta una versione con il tipo:
        //std::get<double>(t);  //funziona solo se la chiamata al tipo non è ambigua, ho un solo double-->OK

    
    
};
