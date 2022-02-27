#include <iostream>
using namespace std;


class Resource{
    
public:
    
     Resource();
     Resource(double j);
    ~Resource();
     Resource(const Resource&);  //Copy CTOR
     Resource(Resource&&);  //Move CTOR

     void move(Resource &);
     

     double *contenuto;
    
};


Resource::Resource(){
    contenuto = new double [100000];
    for (int i = 1; i<100000; i++){
        contenuto[i]=3.14;
    };
};


Resource::Resource(double j){
    contenuto = new double [100000];
    for (int i = 1; i<100000; i++){
        contenuto[i]=j;
    };
};


Resource::~Resource(){
     delete [] contenuto;
};


Resource::Resource(const Resource& copia){
    contenuto = new double [100000];
    for (int i = 1; i<100000; i++){
        contenuto[i] = copia.contenuto[i];
    };
    
    cout << "COPY CTOR" <<endl;
};
    

Resource::Resource(Resource && dying){
    
     contenuto=dying.contenuto;
     dying.contenuto= NULL;
     
     cout << "MOVE CTOR" <<endl;
 };




 void Resource::move(Resource & dest){
     
     delete [] dest.contenuto;
     dest.contenuto = contenuto;
     contenuto = NULL;
 };

  void swap(Resource & a , Resource & b);
  void swap(Resource & a , Resource & b){
     
     double * appo = a.contenuto;
     a.contenuto=b.contenuto;
     b.contenuto=appo;    
     
 };   
 
 Resource gimme(){
     
     return Resource(2.1);
 };
 
 
 
int main(){
    
    Resource r;
    
  for (int i = 1; i<10; i++){
       cout<<"r.contenuto[" << i << "] = "<< r.contenuto[i] << endl; 
    };
    
   Resource r2(5.5);
   
   for (int i = 1; i<10; i++){
       cout<<"r2.contenuto[" << i << "] = "<< r2.contenuto[i] << endl; 
    };
   
    
    cout<<endl;
    cout << " ------------------------------------------------- " <<endl;
    cout<<endl;
    
    
    
    swap(r , r2 );
    
    for (int i = 1; i<10; i++){
       cout<<"r.contenuto[" << i << "] = "<< r.contenuto[i] << endl; 
       cout<<"r2.contenuto[" << i << "] = "<< r2.contenuto[i] << endl; 
    };
  

    cout<<endl;
    cout << " ------------------------------------------------- " <<endl;
    cout<<endl;
    
    
    //COPY CTOR
    Resource rC(r);
    for (int i = 1; i<10; i++){
       cout<<"rC.contenuto[" << i << "] = "<< rC.contenuto[i] << endl; 
    };
    
    
    cout<<endl;
    cout << " ------------------------------------------------- " <<endl;
    cout<<endl;
    
    
   //MOVE CTOR 
    Resource rM(gimme());
     for (int i = 1; i<10; i++){
       cout<<"rM.contenuto[" << i << "] = "<< rM.contenuto[i] << endl; 
    };
    
    
    cout<<endl;
    cout << " ------------------------------------------------- " <<endl;
    cout<<endl;
    
    
    //move
    
    Resource destinazione(9.1);

     for (int i = 1; i<10; i++){
       cout<<"rIni.contenuto[" << i << "] = "<< r2.contenuto[i] << endl; 
    };

     for (int i = 1; i<10; i++){
       cout<<"rDEST.contenuto[" << i << "] = "<< destinazione.contenuto[i] << endl; 
    };
    
    r2.move(destinazione);

     for (int i = 1; i<10; i++){
       cout<<"rMoved(DEST).contenuto[" << i << "] = "<< destinazione.contenuto[i] << endl; 
    };

    
};
