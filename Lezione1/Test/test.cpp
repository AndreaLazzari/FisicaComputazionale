#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <fstream>


 using namespace std;

 
int main(){
 
 int appo=0;
 int quanti=0;
 int *vett;
 char nomeFile[100]= "elenco.txt";
 ifstream file_in;

 file_in.open(nomeFile);
  if(file_in.fail()){
        cout << endl <<"Problema apertura file!!!!" << endl;
    }
 
    file_in >> appo;
    while(!file_in.eof() ){
    quanti++;
    file_in >> appo;
    }

    file_in.close();
    file_in.open(nomeFile);     
 
    vett = new int[quanti];

    for(int i=0; i<quanti; i++){
        file_in >> vett[i];
    }
    file_in.close();
    
    //ho riempito il vettore con i numeri
    
    
div= new int[99999];    //manca un ragionamento su quanti al massimo sono i divisori dei numeri presenti

int n=1;
int j=0;

for (int i=0; i<quanti; i++){

    do {
    
    if (vett[i]%n == 0) {
      
        div[j]=n;
        };
    
        n++;
    } while (vett[i] <= n);

}
 
 
//manca il controllo sui divisori uguali


return 0;
}
