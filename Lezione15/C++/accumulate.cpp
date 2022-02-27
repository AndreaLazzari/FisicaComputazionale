#include<vector>
#include<iostream>
#include<numeric>
#include<functional>

using namespace std;


template <typename type>
type product (type lhs , type rhs){ return lhs*rhs;};
  

//callable entity - tutto ciò che ha un operator()

struct Prod{
  
 int operator() (int i , int j) { return i*j; };
    
};



int main(){
    
    vector<int> v = {3,5,6,8,10,11};
    Prod p;
    
    cout << accumulate( v.begin() , v.end() , 0 ) <<endl;
    
    //accumulate( it1, it2 , daDovePartelaSomma )
    
    
    
    //con accumulate faccio la produttoria
    
    cout << accumulate( v.begin() , v.end() , 1 , product<int> ) << endl
         << accumulate( v.begin() , v.end() , 1 , p ) <<endl
         << accumulate( v.begin() , v.end() , 1 , Prod() ) <<endl
         << accumulate( v.begin() , v.end() , 1 , std::multiplies<int>() ) <<endl;
  
    
  
  
  
  
};
