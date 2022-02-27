/* Problemi del codice da risolvere */
//---Se chiedi a Traffic di generare piu' auto di quante ce ne stanno nella strada entra in un loop infinito
//---Se si prova a simulare tante sessioni di fila avviando piu' volte l'eseguibile, il generatore di numeri casuali "non cambia seed abbastanza velocemente"
//   e vengono generate molte sessioni di fila con le stesse identiche auto
//   Il problema non si pone se il programma e' avviato una sola volta, quindi tutti i vari test in cui si avviano millemila sessioni di Traffic dobbiam farli tutti in questo sorgente

#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <cstdlib>        //Serve per rand(), che genera numeri casuali, e per srand(int), che imposta il seed del generatore
#include <ctime>          //Serve per time(NULL)
using namespace std;

struct Car{
  Car(int x1 = 0, int x2 = 0, string dir = "n"): position({x1,x2}), direction(dir) {}
  Car(pair<int,int> x = {0,0}, string dir = "n"): position(x), direction(dir) {}    //Aggiunto un costruttore che prende un pair<int,int> invece che due int, mi sembrava piu' sensato
private:
  pair<int,int> position;
  string direction;

public:
  pair<int,int> get_pos() {return position;}
  string get_dir() {return direction;}
  void set_pos(pair<int,int> newpos) {position = newpos;}
  void set_dir(string newdir) {direction = newdir;}
  bool step_forward(bool, bool, bool, bool, int);  //Nota: gli ho aggiunto che prende come input anche la dimensione della strada, contenuta in Traffic (v.poi)
  void change_dir();
  void check(int);                                 //Nota: gli ho aggiunto un input intero che indica la dimensione del reticolo (impostata su Traffic)
                                                   //cosi' non deve necessariamente essere un quadrato 100x100
};

//Si puo' fare che Traffic prenda altri veicoli oltre che Car, ma non credo si faccia easy con i template:
//Non puoi semplicemente fare un template <typename T> e inizializzare un vector<T>, perche' dovrebbe contenere tutti oggetti dello stesso tipo
//Si puo' fare con l'ereditarieta' (si costruisce un'unica struct Vehicle di cui Car e' una delle possibili sottostruct, per poi fare un vettore di Vehicle in Traffic) ma zero sbatti
//Per ora lo fo solo con le macchine, al max si modifica poi
struct Traffic{
  Traffic(int ncars = 0, int dim = 0): dimension(dim) { for(int i = 0; i < ncars; ++i) generate(); }  //Genera ncars macchine (generate() l'ho definita dopo) in un reticolo (dim)x(dim)  
private:
  vector<Car> vehicles;             //Vettore di macchine (a gestire la dimensione ci pensa lui spero)
  int dimension;                    //La strada sara' un quadrato (dimension)x(dimension)

public:
  void generate();                  //Genera una macchina, assicurandosi di piazzarla in un posto libero e sbattendola in veichles
  bool isTaken(pair<int,int>);      //Controlla che la posizione input sia occupata (vuota = 0, piena = 1)
  int tick();                       //Fa scorrere il tempo di un'unita' (prova a spostare le macchine)
                                    //Nel caso ci servisse, gli faccio restituire come output il numero di macchine che si son mosse in quel tick
  void printTraffic();              //Un comando che stampa la posizione e la direzione di marcia di ogni auto, per verificare che il programma funzioni
  
};

/****DEF CLASSI****/

/*Car*/

void Car::check(int limits){                           //Aggiunto l'int limits
  if(position.first == limits+1) position.first = 1;
  if(position.second == limits+1) position.second = 1;
  //Ci siam dimenticati del caso in cui la macchina "esca" da sotto/sinistra anziche' da sopra/destra:
  if(position.first == 0) position.first = limits;
  if(position.second == 0) position.second = limits;
}

void Car::change_dir(){                              //Ocio, ho controllato il comando str.compare() e, se direction e "w"/"a"/"s"/"d" sono uguali,l'output di direction.compare(dir) e' 0, non 1
                                                     //Per far si che si entri nell'if quando direction e la direzione sono uguali ci controlla che l'output sia ==0 (Prima era ==1)
                                                     //Anche aggiunto dei return: prima change_dir impostava sempre la direzione verso nord visto che, entrato in un if,
                                                     //si entrava necessariamente anche negli altri, visto che puntare a nord ti imposta a est, puntare a est ti imposta a sud, ecc ecc
  if(direction.compare("n")==0) {direction = "e"; return;}
  if(direction.compare("e")==0) {direction = "s"; return;}
  if(direction.compare("s")==0) {direction = "w"; return;}
  if(direction.compare("w")==0) {direction = "n"; return;}
}


bool Car::step_forward(bool n, bool s, bool e, bool w, int limits){                        //Aggiunto l'int limits
  if(n==1 && s ==1 && e ==1 & w ==1) return 0;
  if(n==0 && direction.compare("n")==0){ position.second += 1; check(limits); return 1; }  //Anche qua i compare vanno cambiati con ==0, senno' non entra mai in nessun if e si impalla qua
  if(s==0 && direction.compare("s")==0){ position.second -= 1; check(limits); return 1; }
  if(e==0 && direction.compare("e")==0){ position.first += 1; check(limits); return 1; }
  if(w==0 && direction.compare("w")==0){ position.first -= 1; check(limits); return 1; }
  change_dir();
  step_forward(n,s,e,w, limits);                                          //Ocio che anche qua va aggiunto l'int limits
  return 1;
}

/**/

/*Traffic*/

void Traffic::generate(){
  //rand()%n restituisce un numero intero tra 0 e n-1, quindi rand()%n +1 lo restituisce tra 1 e n
  pair<int,int> newpos = {rand()%dimension + 1, rand()%dimension + 1};   //genero una posizione casuale, {x,y} nel quadrato di vertici {1,1} e {dimension,dimension}
  while(isTaken(newpos)){
    newpos = {rand()%dimension + 1, rand()%dimension + 1};
  }                                                                      //rigenera la posizione finche' non ne trova una libera (esce dal while se isTaken(newpos) == false)
                                                                         //Impallato qui per sempre se la strada e' piena
  string newdir;
  int pick = rand()%4 + 1;                                               //Genera la direzione
  if(pick == 1) newdir = "n";
  if(pick == 2) newdir = "s";
  if(pick == 3) newdir = "e";
  if(pick == 4) newdir = "w";
  
  Car newcar(newpos, newdir);                                            //Inizializzo la nuova auto con newpos/newdir e la pusho in vehicles
  vehicles.push_back(newcar);
}

bool Traffic::isTaken(pair<int,int> checkpos){
  for(auto &i: vehicles) { if(i.get_pos() == checkpos) {return 1;} }       //Checka se la posizione di input e' occupata da una delle auto in vehicles
  return 0;                                                                //Se non trova corrispondenze ritorna 0
}
int Traffic::tick(){
  int nmoves = 0;
  int moved = 0;
  bool nCheck, sCheck, eCheck, wCheck;

  for(auto &i: vehicles){                                 //Provo a muovere ogni auto i-esima: per ogni auto controllo lo stato di n,s,e,w e do i risultati a i.step_forward()
    nCheck = 0; sCheck = 0; eCheck = 0; wCheck = 0;       //Resetto le variabili di controllo a ogni auto in vehicles
    
    //Controllo Nord della macchina i-esima, attenzione alle condizioni a contorno periodiche se y e' al massimo
    if(i.get_pos().second == dimension){                 //Se ha coordinate {x,dimension} controllo se e' libera {x,1}
      nCheck = isTaken({i.get_pos().first, 1});
    }
    else{                                                //Senno' controllo {x,y+1}
      nCheck = isTaken({i.get_pos().first, i.get_pos().second + 1});
    }

    //Controllo Sud della macchina i-esima, attenzione alle condizioni a contorno periodiche se y e' al minimo
    if(i.get_pos().second == 1){                        //Se ha coordinate {x,1} controllo se e' libera {x,dimension}
      sCheck = isTaken({i.get_pos().first, dimension});
    }
    else{                                              //Senno' controllo {x,y-1}
      sCheck = isTaken({i.get_pos().first, i.get_pos().second - 1});
    }
    
    //Controllo Est della macchina i-esima, attenzione alle condizioni a contorno periodiche se x e' al massimo
    if(i.get_pos().first == dimension){               //Se ha coordinate {dimension,y} controllo la posizione {1,y}
      eCheck = isTaken({1,i.get_pos().second});
    }
    else{                                            //Senno' controllo {x+1,y}
      eCheck = isTaken({i.get_pos().first + 1, i.get_pos().second});
    }
    
    //Controllo Ovest della macchina i-esima, attenzione alle condizioni a contorno periodiche se x e' al minimo
    if(i.get_pos().first == 1){                     //Se ha coordinate {1,y} controllo la posizione {dimension,y}
      wCheck = isTaken({dimension, i.get_pos().second});
    }
    else{                                           //Senno' controllo {x-1,y}
      wCheck = isTaken({i.get_pos().first - 1, i.get_pos().second});
    }

    moved = i.step_forward(nCheck,sCheck,eCheck,wCheck,dimension);     //Finalmente muovo la macchina i-esima, dando a step_forward() gli stati delle zone vicine e la dimensione della strada
                                                                       //Gia' che ci sono mi salvo nell'intero moved se la macchina i-esima si e' mossa (1) o no (0)
    nmoves += moved;                                                   //aggiungo a nmoves 0 oppure 1
  }
  
  return nmoves;                                                       //Finisco ritornando il numero di auto mosse in questo tick()
}

void Traffic::printTraffic(){
  for(int i = 0; i < vehicles.size(); ++i){                            //Uso degli iteratori interi anziche' fare for(Car i: vehicles) cosi' posso enumerarli
    cout << "Veicolo n.: " << i+1 << "      " << "Posizione: (" << vehicles[i].get_pos().first
         << ", " << vehicles[i].get_pos().second << ")      Direzione: " << vehicles[i].get_dir() << endl;
  }
}

int main(int argc, char** argv){                                      //L'ho scritto dopo ma vb, per usare sto file fai ./nomefile [numeroCars] [dimensioneReticolo]
  if(argc != 3){
  cout << "Usage: ./ex_27mar_2 [cars_num] [grid_side_dim]" << endl;
  return -1;
  }
  srand(time(NULL));              //Imposta il seed del generatore di numeri casuali all'orologio del pc (time(NULL) restituisce in secondi il tempo passato dalla UNIX era, se ti interessa)
                                  //Per rand() (usato poi) e srand(int) si include <cstdlib>, per time(NULL) si include <ctime>
  Traffic test(atoi(argv[1]),atoi(argv[2]));                         //Inizializzo Traffic con numeroCars e dimensione passate all'avvio
  cout << "Generato un campo di test con "<< argv[1]<<" auto e "<< argv[2]<<"x"<<argv[2] <<" = "<< (atoi(argv[2]))*(atoi(argv[2]))<<" blocchi disponibili." << endl
       << "Stato iniziale:" << endl;
  test.printTraffic();
  cout << endl << "Si procede con 5 tick, muovendo le macchine una a una a ogni tick, rispettando l'ordine del vettore." << endl << endl;
  for(int i = 0; i < 5; ++i){
    cout << "Tick no. " << i+1 << endl;
    test.tick();
    test.printTraffic();
    cout << endl << endl;
  }
} 
