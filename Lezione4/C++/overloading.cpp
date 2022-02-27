// signature delle funzioni : identificativo che contiene 
// il nome della funzione e i tipi dei parametri
// (il tipo di ritorno della funzione no)


   // funzioni di un "overload set" si distinguono per la signature

 void funz(int , long );

 void funz(double , double , double );  //numero parametri diversi e tipi dei parametri diverso

                            

//int funz(int , long)  // illegale, non basta cambiare solo il tipo di ritorno per fare overloading
 
 
 
//il "tipo" di una funzione include invece il tipo di ritorno:
// ad esempio     int funz(int , long)      è       int(int,long)
 
 
 
