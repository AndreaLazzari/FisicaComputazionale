// le referenze sono come puntatori "costanti" 
// (non possono essere spostati)
// che vengono dereferenziati automaticamente
// e devono essere inizializzate


void incr(int & ref) {
  ++ref;
}


int main() {

  int i = 5; int j = 8;
  int & ri = i; // ri e' una referenza che si riferisce (alias!) a i

  //ri = j; // scrive j in i, *non* sposta la referenza

  ri = 10;
  incr(i);  
  // la prima cosa che accade nella chiamata a funzione e' "int & ref = i" (la referenza si lega alla variabile i)
  // cioe' il parametro locale ref viene inizializzato con l'argomento i
  // (se il parametro della funzione fosse stato "int j", l'inizializzazione "int j = i" avrebbe eseguito una copia e l'incremento non avrebbe avuto effetto, sarebbe stato solo locale)

  return i;    //eseguo il programma e chiamo la stringa
               // echo $?

}
  
