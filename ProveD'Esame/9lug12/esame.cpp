#include<iostream>
#include<cmath>

using namespace std;

class Solido{
    
public:
    Solido(){};
     virtual double Volume()=0;
     virtual double Superficie()=0;
};


class Scatola{
    
public:
    Scatola(int dim=0):dimensioni(dim){};
    ~Scatola(){delete [] *solidi;};
    
     void aggiungi(Solido* s){
         solidi[dimensioni]= s;
         dimensioni++;
      };
    
     double volumeTotale(){
         double v=0;
        for(int i=0; i<dimensioni;++i){
           v+=solidi[i]->Volume();
        };
        
        return v;
      };
    
    
     double superficieTotale(){
         double s=0;
         for(int j=0; j<dimensioni; ++j){
             s+=solidi[j]->Superficie();
             
         };
         
       return s;  
    };
     
private:
    Solido * solidi[100];
    int dimensioni;
    
};


class Cilindro:public Solido{
    
public:
   Cilindro(double raggio , double altezza):r(raggio),h(altezza){};
   ~Cilindro(){};
   
   double Superficie(){return ((2*M_PI*r*h) + 2*(M_PI*r*r));};
   double Volume(){return M_PI*(r*r)*h;};
    
private:
   double r,h;
    
};


class Cubo:public Solido{
    
public:
    Cubo(double lato):l(lato){};
    ~Cubo(){};
    
    double Superficie(){return 6*l*l;};
    double Volume(){return l*l*l;};
    
private:
   double l;
    
};


class Sfera:public Solido{
    
public:
    Sfera(double raggio):r(raggio){};
    ~Sfera(){};
    
    double Superficie(){return 4.*M_PI*r*r;};
    double Volume(){return 4./3. * M_PI* (r*r*r);};
    
private:
   double r;
    
};


int main(){
    
    Cilindro *cil= new Cilindro(5,5);
    Cubo *cub=new Cubo(4);
    Sfera *sf=new Sfera(M_PI);
    
    Scatola *sc=new Scatola();
    
    sc->aggiungi(cil);
    sc->aggiungi(cub);
    sc->aggiungi(sf);
    
    
   double vtot=sc->volumeTotale();
   double stot=sc->superficieTotale();
   
   cout<<"Volume totale : "<< vtot<<endl;
   cout<<"Superficie totale : "<< stot<<endl;
   
   delete cil;
   delete cub;
   delete sf;
   
   
};
