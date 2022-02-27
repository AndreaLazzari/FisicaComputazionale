#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Pub{
    
    
public:
    Pub(string s , int a=2019):t(s),anno(a){};
    ~Pub(){};
    
    Pub(const Pub& copia):t(copia.t),anno(copia.anno){};  //Copy CTOR
    
    void print(){cout<< t <<" ( "<< anno <<" )"<<endl; };   //print()
    
    Pub ( Pub  p1 , Pub  p2){   //Special CTOR
        
        if(p1.anno > p2.anno){
           t=p1.t;
           anno=p1.anno;
        } else{
           t=p2.t;
           anno=p2.anno;
        };
    
    };
    
    
    Pub(Pub && dying){       //move CTOR
     t=std::move(dying.t);
     anno=std::move(dying.anno);
    };
    
    
   bool check ( Pub p1 , Pub  p2 ){
     if( p1.t == p2.t ) {return true;}
        else { return false;}
                               };
    
    string get_tit(){return t;};
    
private:
   string t;
   int anno;
    
};



class Researcher{
    
public:
    
    Researcher(vector<Pub> vett){
        for(auto i:vett){
            v.push_back(i);
        };
    };
    
    ~Researcher(){};
    
    
    int n_pub(){return v.size();};
    
    vector<Pub> get_pubs() const{ return v;};
    //per permettere l'accesso anche in scrittura
    //occorrerebbe omettere "const"
    
    
    
private:
  vector<Pub> v;  
    
};



class Database{


public:
 Database(){};
 ~Database(){};

//  void update(Researcher & r){
//      ric.push_back(r);
//     for(int i=0; i<r.n_pub();++i){
//      m[r.get_pubs()]+=1;
//  };
//  };
     
     
//   void cite(Pub p, int n){
//       for(auto j:m){
//         j[p.get_tit()].second+=n;  
//       };
//   };
//  
 
private:
 vector<Researcher> ric;
 map<Pub,int> m;

};  

int main(){
    
    Pub pr1("hello",2300);
    Pub pr2("hi",2000);
    
    Pub pr3(pr1, pr2);
    
    pr3.print();
    
    
    Pub pub1("C++");
    Pub pub2(std::move(pub1));
    pub1.print();
    pub2.print();   //il costruttore di pub2 trasferisce 
                        //l'ownership della risorsa
    

    vector<Pub> v2={pr1,pr2,pr3};
    
    Researcher v3(v2);
    
    cout<<v3.n_pub()<<endl;
    
   
    
};
