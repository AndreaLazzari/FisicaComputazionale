#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>


using namespace std;

class Vector2{
    
public:
   Vector2(double a=0, double b=0):x(a),y(b){};
   ~Vector2(){};
    
   Vector2(const Vector2 & copia){ 
       x=copia.x;
       y=copia.y;
   };
   
   
   double dot(Vector2 v){return (x*v.x + y*v.y);}; 

   double norm(){return sqrt(x*x+y*y);};
   
   
  virtual Vector2 normalized(){
      
      return Vector2(x/norm(), y/norm());
  };
    
  double get_x(){return x;};
  double get_y(){return y;};
  
private:
    double x,y;
    
};


double angle(Vector2 v1 , Vector2 v2){
    
    return (acos( v1.dot(v2) / (v1.norm()*v2.norm()))*180/M_PI);
    
};

 template<typename type>
 bool pred(type lhs, type rhs){
     Vector2 e(1,0);
     
    return angle(lhs,e) < angle(rhs,e); };
    
    
int main(){
    
    Vector2 v1;
    Vector2 v2(v1);
    Vector2 v3(1.,3.);
    
    cout<<" v1 " << v1.get_x()<< "  " << v1.get_y()<<endl;
    
    cout<<" v2 " << v2.get_x()<< "  " << v2.get_y()<<endl;
    
    
    cout<<endl<<endl;
    
    cout<<" v3 " << v3.get_x()<< "  " << v3.get_y()<<endl;
    
    
    cout<<v3.normalized().get_x()<<endl;
    
    cout<<" v3 " << v3.get_x()<< "  " << v3.get_y()<<endl;
    
    
    cout<<endl<<"----------------------------"<<endl;
    
    Vector2 v(2.,2.);
    Vector2 w(1.,-1.);
    
    cout<<"v.w = " << v.dot(w)<<endl;
    cout<<"w.v = " << w.dot(v)<<endl;
    
    Vector2 pr1(1./sqrt(2),1./sqrt(2));
    Vector2 pr2(1./sqrt(2),-1./sqrt(2));
    
    cout<< angle(pr1,pr2)<<endl;
    
    cout<<endl<<"----------------------------"<<endl;
    
    
    vector<Vector2> V;
    
    for (int i=0; i<10000; i++){
      V.push_back( Vector2(drand48(),drand48()) );
    };
    
    
    sort(V.begin(),V.end(),pred<Vector2>);
    
    Vector2 e(1,0);
    
  cout<< angle(V.front(),e) << "   " << angle(V.back(),e)<<endl;
    
    
    
    
    
};
