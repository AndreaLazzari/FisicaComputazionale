#include <vector>
#include <utility>
#include <iostream>
#include <string>
#include <cstdlib> 
#include <cmath>
#include <fstream>


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


class Car {
    
 public:
     
    Car (int x1 = 0 , int x2 = 0 , string dir = "n" ): position({x1,x2}), direction(dir) {};
    Car (pair <int , int > x = {0,0} , string dir = "n"): position(x), direction(dir) {};
    
    ~Car(){};
    
    
    pair<int,int> get_pos(){return position;};
    string get_dir(){return direction;};
    
    
    void set_pos(pair<int,int> newpos) {position = newpos;};
    void set_dir(string newdir){direction=newdir;};
    
    bool step_forward(bool , bool , bool , bool , int);
    
    void change_dir();
    void check(int );
    
    
 private: 
     pair<int,int> position;
     string direction;
    
    
};


void Car::change_dir(){
    if (direction.compare("n")==0) {direction="e"; return;};
    if (direction.compare("e")==0) {direction="s"; return;};
    if (direction.compare("s")==0) {direction="w"; return;};
    if (direction.compare("w")==0) {direction="n"; return;};
};

bool Car::step_forward(bool n, bool s, bool e , bool w, int limits){
    if( n==1 && s==1 && e==1 && w==1) {return 0;};
    
     if( n==0 && direction.compare("n")==0) { 
                                  position.second +=1; 
                                  check(limits);
                                  return 1;
    };
    
     if( s==0 && direction.compare("s")==0) { 
                                  position.second -=1; 
                                  check(limits);
                                  return 1;
    };
    
    
     if( e==0 && direction.compare("e")==0) { 
                                  position.first +=1; 
                                  check(limits);
                                  return 1;
    };

     if( w==0 && direction.compare("w")==0) { 
                                  position.first -=1; 
                                  check(limits);
                                  return 1;
    };

    change_dir();
    step_forward(n,s,e,w, limits);
    return 1;
};

void Car::check(int limits ){
    
    if (position.first == limits+1){ position.first=1;};
    if (position.second == limits+1){ position.second=1;}; 

    if (position.first == 0){ position.first=limits;};
    if (position.second == 0){ position.second=limits;};     
        
};

/*-----------------------------------------------------_*/



class Traffic {
    
    
public:
    
    Traffic(int nCars = 0, int dim = 0): dimension(dim) { for(int i=0; i<nCars; ++i) newVehicle(); };
    
    ~Traffic(){};
    
    void newVehicle();  //new car in un posto *libero*
    
    bool isTaken(pair <int,int> ); //Controlla che la posizione input sia occupata (vuota = 0, piena = 1)
    
                   
    int move_traffic(); //scorro il tempo e muovo le macchine
    
    
    void printTraffic(); //stampo la posizione e la direzione di marcia di ogni auto
    
private:
    vector <Car> vehicles;
    int dimension;
};


void Traffic::newVehicle(){
   
    Random a(7);
    
    pair<int,int> newpos = {int(a.Uniform(1.,dimension)) , int( a.Uniform(1.,dimension))};
    
    while(isTaken(newpos)){
        newpos = { int(a.Uniform(1.,dimension)) , int(a.Uniform(1.,dimension)) };
    };   //ripete la generazione finchè la newCar è generata in un posto libero
    
    
    string newdir;   //genero la direzione
    
    int pick = int(a.Uniform(1.,4.));
    
    if(pick == 1) newdir = "n";
    if(pick == 2) newdir = "s";
    if(pick == 3) newdir = "e";
    if(pick == 4) newdir = "w";
    
    Car newCar(newpos, newdir);
    
    vehicles.push_back(newCar);
    
};




bool Traffic::isTaken(pair <int,int> checkpos){
    
    for (auto &i: vehicles) {
        if(i.get_pos() == checkpos) {return 1;}
    };
    
    return 0;   //1 = pos_occupata , 0 = pos_libera
        
    
};




int Traffic::move_traffic(){
    int nmoves=0;
    int moved=0;
    
    bool nCheck, sCheck, eCheck, wCheck;
    
    
    for (auto &i: vehicles){
        
        nCheck=0;
        sCheck=0;
        eCheck=0;
        wCheck=0;
        
        
        
        //controllo Nord (problema se y=max)
        if (i.get_pos().second == dimension){
          nCheck = isTaken({i.get_pos().first,1});
        } 
          else {
        nCheck = isTaken({i.get_pos().first, i.get_pos().second +1 });
          };
          
          
          
    //controllo Sud (problema se y=min)
        if (i.get_pos().second == 1){
          sCheck = isTaken({i.get_pos().first,dimension});
        } 
          else {
        sCheck = isTaken({i.get_pos().first, i.get_pos().second -1 });
          };
        
          
    //controllo Est (problema se x=max)
        if (i.get_pos().first == dimension){
          eCheck = isTaken({1,i.get_pos().second});
        } 
          else {
        eCheck = isTaken({i.get_pos().first +1 , i.get_pos().second});
          };
         
          
          
     //controllo West (problema se x=min)
        if (i.get_pos().first == 1){
          wCheck = isTaken({dimension,i.get_pos().second});
        } 
          else {
        wCheck = isTaken({i.get_pos().first -1, i.get_pos().second});
          };
     
          
    moved = i.step_forward(nCheck,sCheck,eCheck,wCheck, dimension);    //dopo tutti i controlli muovo la macchina i-esima, ho controllato le "caselle" vicino ad essa e ho tenuto conto delle dimensioni della strada
        
    nmoves += moved; //aggiunto 0 se la i-esima è rimasta ferma (c'era return 0 in step_forward) o aggiunto 1 se la i-esima si è mossa 
    
    };  //end for, mosso tutto il traffico
    
    
    //cout << " Si sono mossi " << nmoves <<" veicoli"<<endl;
    
    return nmoves;   //return quante si sono mosse
    
};



void Traffic::printTraffic(){
    
    for (int i=0; i < vehicles.size() ; ++i){
        
     cout<<" Veicolo n° : " << i+1 << ",    Posizione:  ( " << vehicles[i].get_pos().first << " , " << vehicles[i].get_pos().second << " ),    Direzione :  " << vehicles[i].get_dir() <<endl;        
        
    };
    
};



int main(int argc, char** argv){

    if (argc != 3){
        
        cout << "Please use : ./traffic [num_Cars] , [dimension_of_street]" <<endl;
        
    return -1;
    
    };
    
    if (atoi(argv[1]) > (atoi(argv[2]))*(atoi(argv[2])) ){
        
      cout << " num_Cars is more than the dimension_of_street!! Impossible situation " <<endl;
        
    return -1;
    
    };
    
    int nCars=atoi(argv[1]);
    double dim =(atof(argv[2]))*(atof(argv[2]));
    
    Traffic test( atoi(argv[1]), atoi(argv[2]));
    
    /*
    cout <<endl <<endl;
    
    cout << "Generata una strada quadrata di test di lato "<< argv[2] <<" con conseguenti "<< (atoi(argv[2]))*(atoi(argv[2])) << " caselle disponibili, occupate al momento da " << argv[1] << " veicoli " << endl;
    
   
    cout << " Stato iniziale: "<<endl;
    test.printTraffic();
    
    cout << endl << "Si procede facendo scorrere il tempo di 5 unità, facendo muovere i veicoli uno ad uno, rispettando l'ordine del vettore " << endl;
    
    cout <<endl <<endl;
    
    for(int i = 0 ; i < 5; ++i){
        
        cout<< " time = " << i+1 <<endl;
        test.move_traffic();
        test.printTraffic();
        cout <<endl <<endl;
        
    };  

    */
   
   double ferme=0;
   double fermetot=0;
   
   ofstream file_out;

   file_out.open("grafico1.dat");
   
   
   
for (int j=0; j<100; ++j){
    
   for(int i = 0 ; i < 1000; ++i){
        
       ferme += (nCars - test.move_traffic());
       
   };   
   
      fermetot= (ferme/1000);
   
     file_out << double(nCars)/dim << " " << fermetot << endl;
     ferme=0;
     fermetot=0;
     
     for (int k=0; k<10; ++k){
        test.newVehicle();
        nCars+=1;
     };     
     
     
};
     
     
   file_out.close();
   
};
