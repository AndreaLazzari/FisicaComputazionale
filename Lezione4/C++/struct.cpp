// - aggregazione dati e comportamento
// - incapsulamento


//struct e class sono identiche
//unica differenza : struct ha "public" come default e class ha "private"


struct Body{
private:  //dettagli dell'implementazione
    
    double mass;
    double vel;
    
public: //interfaccia dell'implementazione
    
    void accel(double );   //pura dichiarazione
   
    //idioma get/set ("extra level of indirection")
    // - controllo più fine degli accessi ai membri privati
    // - implementare vincoli/invarianti (relazioni tra variabili/ limiti veri e propri)
    // - notifiche/log o aggiornamenti
    
    void set_mass(double m) { mass = m; };
    double get_mass() { return mass; };

};


//definizione (nota: accel sta nello spazio dei nomi Body::)

 void Body::accel(double impulse){
 
    /*con o senza this->*/vel += impulse/mass;   
    this;   //puntatore all'oggetto che ha fatto al chiamata
 }
 
 
 
 int main(){
     
  Body b,b1;    //Body è il *tipo* , b è la *variabile* (oggetto)
  //b.mass=3.1; b.vel=0.;  //non posso, sono membri private
  b.accel(1.);
  b1.accel(3.);
  
 };
 
 
 
 
 //guidelines per uso public/private/protected
 //vedi Scott Meyers "Effective C++"
