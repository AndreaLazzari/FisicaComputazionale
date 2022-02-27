//chiamare :
// cat ulysses.txt | ./zipf

#include<set>
#include<vector>
#include<map>
#include<iostream>
#include<utility>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

bool confr (pair<string,int> lhs , pair<string,int> rhs){ return lhs.second > rhs.second;};


int main(){
    
 string s;   
 multiset<string>ms;
 map <string,int> m;
 vector<pair<string,int>> v;
 
  while (cin >> s) {
      ms.insert(s);
  };
  
  for ( string i: ms ){
      
      m[i] = ms.count(i);   
    
  };
  
  
  for ( auto i: m){
      
      v.push_back(i);
  };
  
  sort(v.begin(), v.end() , confr);  
  
  
  ofstream file_out;

  file_out.open("output");
  
  for ( auto j:v){
      
    file_out << "Word : " << j.first << "    Molteplicità :   "  << j.second << endl;     
      
    
  };
  
     file_out.close();
  
};
