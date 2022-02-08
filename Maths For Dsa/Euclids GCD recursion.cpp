#include<iostream>
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
    int a = 24 , b = 48 ;
    int ans = check(a,b);
    cout<<ans<<endl;
}