#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Complex{
    
public:
    Complex(): real(0) , im(0) {} ;
    Complex(double a , double b=0) : real(a) , im(b) {};
    void setCart(double a , double b);
    void setPol(double a , double b);
    
    
    double getCartre(){return real; };
    double getCartim(){return im; };
    double getPolmod(){return (sqrt(real*real + im*im)); };
    double getPolth(){return (atan2(im , real)); };
    

    Complex inverso();
    
    
    ~Complex(){};
    
private:
    double real, im;
    
};





void Complex::setCart(double a , double b){
    real=a;
    im=b;
};
  

void Complex::setPol(double a , double b){
   real = a * cos(b);
   im = a * sin(b);
};

Complex somma( Complex z , Complex w );
Complex somma( Complex z , Complex w ){
   
    double sommaRe = z.getCartre() + w.getCartre();
    double sommaIm = z.getCartim() + w.getCartim();
 
        return Complex(sommaRe,sommaIm);
};

Complex prod( Complex z , Complex w );
Complex prod( Complex z , Complex w ){
 
        return Complex( z.getCartre()*w.getCartre() - z.getCartim()*w.getCartim() , z.getCartim()*w.getCartre() + z.getCartre()*w.getCartim() );
};

Complex Complex::inverso(){
 
        return Complex( ( real / getPolmod()*getPolmod() ) , ( (-im) /  getPolmod()*getPolmod() ) );
};





int main(){
    
 //Punto 1   
    Complex z(2,4.2);
    
    cout<<"Il numero complesso e ' : "<<endl;
    cout<<" - in coordinate cartesiane : " << z.getCartre() << " + " << z.getCartim() <<"i  "<<endl;
    cout<<" - in coordinate polari : " << z.getPolmod() << " exp{ i " << z.getPolth() << " } " <<endl;
    
 //Punto   1a
    z.setPol(6, 0.13);
    
    cout<<"Il numero complesso MODIFICATO e ' : "<<endl;
    cout<<" - in coordinate cartesiane : " << z.getCartre() << " + " << z.getCartim() <<"i  "<<endl;
    cout<<" - in coordinate polari : " << z.getPolmod() << " exp{ i   " << z.getPolth() << " } " <<endl;
    
    
 //Punto 2  
    
    Complex w(5,1);
    
    Complex s = somma(3 , w);
    
    cout<<"Il risultato della somma e' : "<<endl;
    cout<<" - in coordinate cartesiane : " << s.getCartre() << " + " << s.getCartim() <<"i  "<<endl;
    cout<<" - in coordinate polari : " << s.getPolmod() << " exp{ i " << s.getPolth() << " } " <<endl;
    
    
    Complex p = prod(z , w);
    
    cout<<"Il risultato della prodotto e' : "<<endl;
    cout<<" - in coordinate cartesiane : " << p.getCartre() << " + " << p.getCartim() <<"i  "<<endl;
    cout<<" - in coordinate polari : " << p.getPolmod() << " exp{ i " << p.getPolth() << " } " <<endl;
    
    
    Complex i = z.inverso();
    
    cout<<"L'inverso e' : "<<endl;
    cout<<" - in coordinate cartesiane : " << i.getCartre() << " + " << i.getCartim() <<"i  "<<endl;
    cout<<" - in coordinate polari : " << i.getPolmod() << " exp{ i " << i.getPolth() << " } " <<endl;
    
    
   //Punto3
    
    ofstream file_out;
    
    file_out.open("dati.dat");   
    
  Complex d(-2.,-2.);
  double incr = (4./100.);
  Complex mappa;
  
    
   for (int j=1 ; j<=100;j++){
       
    for (int i=1; i<=100; i++){
    
        mappa = (prod ( somma( d , -3.).inverso() , somma(d, -3.).inverso() ) );
        file_out << mappa.getCartre() << "   " << mappa.getCartim() << endl;
        d=somma(d , incr);
    };
    
    d=Complex(-2. , d.getCartim() + incr );
    
   }; 
    file_out.close();
    
    
    
};
