// Fasi della compilazione:
// 1) pre-processore (flag -E) -> genera ancora cpp
// 2) compilatore e ottimizzatore (flag -S) -> genera assembly
// 3) assembler (flag -c) -> genera un binario (file oggetto)
// 4) linker (ld) -> genera l'eseguibile


//extern opzionale per le funzioni, indica che la definizione è da qualche altra parte

extern void speak();   //dichiarazione (non definizione o implementazione)
                //da qualche parte esiste già, qui non dico cosa fa, non genero codice, non ha le graffe
                
//extern int i; // anche per le variabili
 
int main(){

    speak();
  
 return 0;   
}
