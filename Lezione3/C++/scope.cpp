//scope delle variabili, ambito di validità e di vita della variabile stessa


int main(){

    {
      bool b = false;   
    }   //qui la variabile b "muore" 
        //b è una variabile "auto" gestita automaticamente dal compilatore


  //b = true;     illegale: b è fuori scope   
    
    
   //per disaccoppiare il tempo di vita della variabile (scope) dal nome usato per riferirsi ad essa
    int *pi;
   
    {
      int i=5;
      pi = &i;
    }
    
    *pi = 3; //ATTENZIONE: undefined behaviour (--> errori a runtime)

};
