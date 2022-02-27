#include<iostream>
using namespace std;

int main(){


  double *pd;
    
    
     {
      pd = new double;     // new alloca la variabile e restituisce un puntatore alla variabile
      //(la variabile sta in una zona chiamata "heap")
     }

     
   *pd = 3.14;
  
   
   delete pd;  // restituisce al runtime enviroment l'area di memoria che avevo allocato con il new
               // può essere chiamato *soltanto* su un puntatore restituito da new
     
     cout<< pd <<endl;
               
     //*pd = 1.;  //non posso, la zona di memoria non è più "mia"         
     
     //posso tuttavia continuare ad utilizzare pd: è una variabile automatica (posso farlo puntare altrove)
      double d;
      pd = &d;
      
               
     /*          
     int i;
     delete &i;
     */  // non posso deallocare una variabile automatica
};
