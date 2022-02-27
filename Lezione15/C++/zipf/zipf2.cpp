//chiamare :
// cat ulysses.txt | ./zipf

#include<vector>
#include<map>
#include<iostream>
#include<utility>
#include<string>
#include<fstream>
#include<algorithm>


using namespace std;


bool confr( pair<string,int> lhs , pair<string,int> rhs) {return lhs.second > rhs.second;};




int main(){
    
    
 string s;   
 map <string,int> m;
 vector<pair<string,int>> v;
 
  while (cin >> s) {
      m[s]+=1;
  };
    
    
  for (auto i:m){ v.push_back(i);};
  
  
  sort(v.begin() , v.end() , confr);
  
      
       ofstream file_out, file_out1;

  file_out.open("output2");
  file_out1.open("grafico.dat");
  
  for ( auto j:v){
      
    file_out << "Word : " << j.first << "    Molteplicità :   "  << j.second << endl;     
    file_out1 << j.second << endl;
    
  };
  
     file_out.close();
   
  
  
  
    
    
    
    
};

