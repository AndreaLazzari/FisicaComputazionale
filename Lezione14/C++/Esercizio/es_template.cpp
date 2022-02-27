#include<iostream>
#include<vector>
#include<set>
#include<string>


//tutti i container della STL hanno un metodo "size()"
//il quale restituisce la lunghezza del container, il suo numero di elementi

using namespace std;


struct Trivial{
    int size(){return 1;};
};



struct MaxMinSize{
   
  unsigned int max_size = 0;  
  unsigned int min_size = 0;   
  
  
  bool recorded = 0;
  
  template <typename type>
  void record(type in){
      
      if(recorded==0){
          max_size = in.size();
          min_size = in.size();
          recorded=1;
      }
      else {
          
        if(max_size < in.size()){ max_size=in.size();};
        if(min_size > in.size()){ min_size=in.size();};
        
      };
  }  
};



int main(){
    
    MaxMinSize r;
    
    vector<int> v = {1,4,5,7,-1};
    set<double> s = {0.2,0.9};
    string hello("hello");
    
    r.record(v);
    r.record(s);
    r.record(hello);
    r.record(Trivial());
    
    //...//
    
    
    cout<< r.max_size << "   " << r.min_size << endl;
    
    
};
