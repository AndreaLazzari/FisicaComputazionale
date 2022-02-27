//la sintassi del range-based for loop funziona per tutti i containers della STL


//scrivere la funzione rectify (anche template di funzione)
//dopo la chiamata v deve essere {4,2,6,7,9,0}

template < typename T >
void rectify( T & vett){
  for(int &i: vett){
      if (i<0) { i = -i; };
  };
    
};


#include <vector>
#include <iostream>
using namespace std;

int main(){
   
    vector<int>v = {-4,2,6,7,-9,0};
    
    for (int i: v){ cout << i << "  "; };
    cout <<endl;
    
    rectify(v);
    
    for (int i: v){ cout << i << "  "; };
    cout <<endl;
    
};

