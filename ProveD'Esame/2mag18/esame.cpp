#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<list>
#include<algorithm>

using namespace std;



class Text{
   
public:
    Text(string s){testo.push_back(s);};
    ~Text(){};
    
    
    Text(const Text & copia){ 
       for(auto i:copia.get_text()){testo.push_back(i);};
        
    };
    
    Text(vector<string>::iterator it1, vector<string>::iterator it2){
     for(auto j=it1; j<it2; ++j){testo.push_back(*j);};
     
     //potrei anche simply testo.assign(it1,it2);
    };
    
  
    
    void print(){
     for(auto i:testo){cout<< i << " ";}
     cout<<endl;
        
    };
    
    int length() const{return testo.size();};
    
    vector<string> get_text() const{return testo;};
        
    
    
private:
    vector<string> testo;
    

};


class Rule{
    
    
public:
 
 Rule(){};
 ~Rule(){};
 
 Rule & add (char x , char y){
     m[x]=y;
     m[y]=x;

     return *this;
 };
     
 
 string * transform(string s){
     
     string * mod= new string[s.size()];
     char appo;
     
     
 for(auto it=s.begin(); it != s.end(); ++it){
         
     appo=*it; 
     
    for(auto itm=m.begin(); itm != m.end(); ++itm){
        
         if ( *it == itm->first  ){
        
         appo=itm->second;
        
         };        
        
    };
    
     mod->insert(it,appo);
    
     };
    
     return mod;
};

private:
   
     map<char,char> m;
    
};



 bool pred(Text lhs, Text rhs){
       
    return lhs.length() < rhs.length(); };



list<Text>::iterator longest(list<Text> l, list<Text>::iterator it1, list<Text>::iterator it2){

auto it = max_element(it1, it2, pred);

return it;
    
};


int main(){
    
    string t = "hello";
    
    Text T(t);
    
    Text s(T);
    
    string lon="ciao tutto bene";
    Text ln(lon);
    
    T.print();
    s.print();
    
    vector<string> v={"a","b","c","d","e","f","g","h"};
    
    vector<string> v2;
    
    auto it1= v.begin();
    auto it2=v.end()-1;
    

    Text prova(it1,it2);
    prova.print();
   cout<< prova.length()<<endl;;
    
   
   Rule r;
   
   
   r.add('x','y').add('a','b').add('k','l');
       
   string spr=("ciao");
   
   

   string *l = new string[4];
  // *l= *r.transform(spr);
   
   cout<<spr<<endl;

//    cout << l <<endl;
  
   
   
//    for(auto i=r.m.begin(); i != r.m.end(); ++i )
       
//    {cout<<(*i).first<< (*i).second<<endl;};
   
   list<Text> lista={T,s,ln};
   

   auto max= longest(lista, lista.begin(),lista.end());
   
   cout<< "lista max : " << (*max).length()<<endl;
   
   
    
};
