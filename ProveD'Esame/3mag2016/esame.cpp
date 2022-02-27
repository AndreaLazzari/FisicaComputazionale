#include<iostream>
#include<utility>
#include<cmath>

using namespace std;

class Pos2D{
    
public:
    
 int x,y;
 
 Pos2D(int p , int s):x(p),y(s){};
 ~Pos2D(){};
 
 Pos2D(const Pos2D & copia){
     x=copia.x;
     y=copia.y;
 };
    
void print() const { cout << x << " , " << y << endl;};



 Pos2D operator + ( Pos2D add ){
      
      Pos2D nuovo( x + add.x , y + add.y);
      
      return nuovo;
};

  bool operator ==( Pos2D confr){

      return ( (x == confr.x) && (y == confr.y));    
};


};



class Walk{
    
    
public:
    Walk(Pos2D p= Pos2D(0,0)): pos(p) {};
    ~Walk(){};
    
    Pos2D get_position() const{
        return pos; };
    
   void operator +=(Pos2D delta){    
       pos= pos + delta;
      
    };
    
    
    void print() const { pos.print(); }
        
protected:
  Pos2D pos;  
    
};


int main(){
    
    Pos2D primo(1,1);
    Pos2D sec(primo);
    
    cout<<sec.x <<"  " << sec.y <<endl;
    
   Pos2D provasomma = primo+sec;
   
    cout<<provasomma.x <<"  " << provasomma.y <<endl;
   
    bool c =  (primo==sec);
   cout<< c << endl;
    

   
   cout<<endl<<"----------------------------"<<endl<<endl;
   
   
   Walk es;
   int i=0;
   Pos2D pos1(0,0);
   
   
   while (  !( pos1 == Pos2D(-5,17) )  ){
       
      es+= Pos2D ( floor(2*cos(i/5.) +0.5) , floor(2*sin(i/5.) +0.5) );
    
      pos1 = es.get_position();
        
       ++i;      
       
   };
   
   
   cout << "Si è arrivati a  ( " << pos1.x <<" , " << pos1.y << " ) dopo "<< i << " iterazioni"<<endl;
   
   
   
    
};
