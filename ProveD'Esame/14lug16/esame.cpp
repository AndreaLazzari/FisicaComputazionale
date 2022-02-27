#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>


using namespace std;

class Auto{
    
public:
    Auto(double forza , double massa=1):f(forza),m(massa){};
    ~Auto(){};
    
    Auto(const Auto& copia){ 
        m=copia.m;
        f=copia.f;
    };
    
    double get_m(){return m;};
    
    double get_acc(){ return f/m;};
    
    
private:
 double m,f; 
 
};


class Checker{
    
    
public:
    
    Checker(double t):tol(t){};
    ~Checker(){};
    
    bool check ( Auto & car ){
     if( car.get_m() >= (1-tol) || car.get_m() <= (1+tol)) {return true;}
        else { return false;}
                                };
 
    
private:
   double tol; 
    
};



vector<Auto>::iterator fastest(vector<Auto>::iterator it1, vector<Auto>::iterator it2){
    
    vector<Auto>::iterator appo=it1;
    
    for(auto j=it1; j!=it2; ++j){
        
        if( j->get_acc() > appo->get_acc()){
            appo=j;
        };
        
};

  return appo;

};


 bool pred(Auto lhs, Auto rhs){
       
    return lhs.get_acc() < rhs.get_acc(); };


   vector<Auto>::iterator fastest_algo(vector<Auto>::iterator it1, vector<Auto>::iterator it2){
       return max_element(it1,it2, pred);
    };

int main(){
    
Checker c(0.03);

Auto car(10,0.99);
cout<< c.check(car)<<endl;

 vector<Auto> v;
 
 for (int i=0; i<1000; i++){
      v.push_back( Auto(drand48() , drand48() + 0.5)  ); 
 };
 
 auto max1=fastest(v.begin(),v.end());
 
 cout << " (FUNZ) Auto con acceleraz massima è : " << (*max1).get_acc() << endl;
 
 auto max2=fastest_algo(v.begin(),v.end());
   
   cout << " (ALGO) Auto con acceleraz massima è : " << (*max2).get_acc() << endl;
    
};
