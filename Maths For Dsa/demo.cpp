    #include <iostream>
#include <cmath>
using namespace std;

int check(int a , int b){
    //base case 

    if(a == 0) 
        return b ;
    
    if(b == 0)  
        return a ;


    if(a > b){
        check(a-b , b);
    }else{
        check(a , b-a);
    }
    
}


int main(){
    long a = 4 ;
    long b = 1  ;

    long gcd = check(a,b);
    int cnt = 0 ;
    if(gcd % 2 == 0){
        if(b > a){
          for(int i = 1 ; i < b ; i++){
            if(i % 2 == 0){
              cnt++ ;
            }
          }
        }else{
          for(int i = 1 ; i <= b ; i++){
            if(i % 2 == 0){
              cnt++ ;
            }
        }
        }
    }else{
      if(b > a){
          for(int i = 1 ; i < b ; i++){
            if(i % 2 == 1){
              cnt++ ;
            }
          }
        }else{
          for(int i = 1 ; i <= b ; i++){
            if(i % 2 == 1){
              cnt++ ;
            }
          }
        }
    }
  double ans = (double(cnt) / double(b) ) ;
  long result = (ans  * 1000000) ;
  cout<<result<<endl ; 
}