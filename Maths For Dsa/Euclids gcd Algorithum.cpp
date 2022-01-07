#include <iostream>
using namespace std;

int check(int a , int  b){
    
    if(a == 0){
        return b;
    }

    if(b == 0){
        return a;
    }

    while(a != b){
        if(a > b){
            a = a-b ;
        }else{
            b = b-a;
        }
    }

    return a;
}

int main(){
    int a = 462 ;
    int b = 1071  ;

    cout<<check(a,b);
}