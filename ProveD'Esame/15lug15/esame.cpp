#include<iostream>
#include <cmath>
#include<vector>
#include<algorithm>


using namespace std;




class Random {

 public: 
   Random(unsigned int seed);
   double Rand();
   double Uniform(double a , double b);

   private:
     unsigned int m_a;
     unsigned int m_c;
     unsigned int m_m;
     unsigned int m_seed;
};


Random::Random(unsigned int seed){
  m_a = 1664525;
  m_c = 1013904223;
  m_m = pow(2,31);
  m_seed=seed;

};


double Random::Rand(){
  m_seed = (m_a*m_seed + m_c)% m_m; 
  return (double) m_seed/(m_m-1);
};

double Random::Uniform(double a, double b){
 return a+(b-a)*Rand();

};



class Spring{
   
public:
    
    Spring(double c , double cel=1): carico(c), k(cel){};
    ~Spring(){};
    
    
    Spring(const Spring & copia){ 
        k=copia.get_k(); 
        carico=copia.get_carico(); 
    };
    
    
    double get_k(){return k;};
    double get_carico(){return carico;};

    
    
    
private:
    double k; //costante elastica
    double carico; //massima forza sostenibile

};



class Checker{
    
    
public:
    Checker(double t):tol(t){};
    ~Checker(){};
    
    bool check ( Spring & molla ){
     if( molla.get_k()> (1-tol) && molla.get_k() < (1+tol)) {return true;}
        else { return false;}
                                };
    
    bool operator()( Spring & molla){                            
        
        return check(molla);
                                };
        
        
private:
    double tol;
    
};


class Factory{
    
public:
     Factory(double valC):C(valC){};
     Factory(Checker c):C(c){};
    ~Factory(){};
    
    Spring * produce(Random* a);
     
    
private:
    Checker C;
    
};


    Spring * Factory::produce( Random * a){
        
    
      double k = a->Uniform(0.8,1.2);
      
      Spring * molla= new Spring( 10., k);
      
      /*if ( C.check(*molla) == true){
        cout<<"La molla ha costante elastica diversa da 1 (entro la tolleranza)"<<endl;}
           else {
              cout<<"La molla ha costante elastica uguale a 1 (entro la tolleranza)"<<endl;
           };          
       */ 
        
    return molla;
          
    };

    
    bool pred(Spring* lhs, Spring* rhs){
       
    return lhs->get_k() < rhs->get_k(); };

    
int main(){
  
     Random *a= new Random(7);
    
    /*
    
    Spring molla1(17,15.);
    Spring molla2(13.,);
    Spring molla3(199,0.9);
    
    Checker c(0.3);
    cout<< c.check(molla1)<<endl;
    cout<< c.check(molla2)<<endl;
    cout<< c.check(molla3)<<endl;
    
    
    cout <<endl<<endl;
    
    cout << c(molla1)<<endl;
    cout << c(molla3)<<endl;
    */
    
    Factory f(0.5);
    
    Spring * m = f.produce(a);
    cout<<m->get_carico()<< "   " << m->get_k() <<endl;

    
    cout <<endl <<" ------------------------------------- "<<endl;
    cout<<endl<<endl;
    
    
    Checker c1(0.1);
    Factory f1(c1);
    

    vector<Spring*> v1;
    
    
    for (int i=0; i<1000; i++){
      v1.push_back(f1.produce(a)); 
    
      //cout<<v1[i]->get_carico()<< "   " << v1[i]->get_k()<<endl;
      
    };
        
    vector<Spring*> v;
    
    for (int i=0; i<20;i++){
        v.push_back(f1.produce(a));
        cout<<v[i]->get_carico()<< "   " << v[i]->get_k()<<endl;
    };
        
    

   auto max=max_element(v.begin(),v.end(), pred);
   
   cout << "molla con costante elastica massima è : " << (*max)->get_k() << endl;
    
    
};
