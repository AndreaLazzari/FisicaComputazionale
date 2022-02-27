#include<iostream>
#include<string>
#include<set>


using namespace std;

class Task{
    
public:
    
    Task(string testo=""):s(testo){};
    ~Task(){};
    Task(const Task& copia):s(copia.s){};
    string get_testo(){return s;};
    
    Task(Task s1 , Task s2):s(s1.s+s2.s){};
    
    
    
private:
    string s;
    
    
};

class Hasher{
    
public:
    
    Hasher(int a=2):iteraz(a){};
    ~Hasher(){};
   
    
    string operator()(Task t){return hash(t.get_testo());};
    
    
    
    
    
    
    
private:
    int iteraz;
    
    
    string hash(string testo){
     
        for(string::iterator it=testo.begin() ; it!=testo.end(); ++it){
        
            if( *it%4==0){
                
             *it=((5*(*it))/4) -25;
             
            } else{
                
                *it=*it-1;
            };
        
    };
   
    return testo;
};
    


};


template<typename T , typename H>
class Queue{
    
public:
  
  Queue(){};
  ~Queue(){};
    
    
private:
  T t; H h;
  set<T> s;
    
};



int main(){
    
    Task t("hello");
    Task cop(t);

    
    cout<< t.get_testo() <<endl<< cop.get_testo()<<endl;
    
    
    Task prova(t,cop);
    
    cout<<prova.get_testo()<<endl;
    
    char c='l';
    cout<<c/4<<endl;
    
    
    
    
    cout<<endl<<"------------------------------"<<endl<<endl;
    

    Hasher h;
    
    string p = h(t);
    
    cout<<endl<<p<<endl;
    
    
    
};
