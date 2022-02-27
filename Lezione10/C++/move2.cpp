#include <iostream>
using namespace std;

//std::move serve a "forzare" lo spostamento
//[ std::move non sposta nulla   -- std::move non genera codice eseguibile ]

#include<utility>
#include<string>


struct Verbose{};


void by_ref(const Verbose &){cout << " lvalue " <<endl;};
void by_ref( Verbose && ){cout << " rvalue " <<endl;};


/*
void swap(string & lhs , string & rhs){
    string tmp = lhs; //copy CTOR
    lhs = rhs;  //copy assignment
    rhs = tmp;
};   //ho fatto 3 copie degli oggetti

*/



void swap(string & lhs , string & rhs){
    string tmp = std::move(lhs); //move CTOR   genera un rvalue ref ( move(lhs) ) ma non tocco lhs
    lhs = std::move(rhs);  //move assignment
    rhs = std::move(tmp);
    
}; //non ho fatto copie di nessuno oggetto!


int main() {
    
    Verbose v;
    by_ref(std::move(v));  //(stampa rvalue)
      //std::move fa un cast a Verbose &&
      //(genera una var di tipo Verbose && a partire da Verbose )
      //fa finta che v sia un temporary (rvalue), semantica di spostamento forzata, permette al pc di rubargli la memoria
    
    
    std::string s(" hello ");
    cout<<s<<endl;
    
    
};
