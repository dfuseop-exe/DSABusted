#include<iostream>
using namespace std;

int factorial(int num){
    int fact = 1;
    for(int i = 1 ; i<= num ; i++){
        fact = fact * i ;
    }
    return fact;
}

int nCr(int n , int r){
    
    int numerator = factorial(n);
    int denomerator = factorial(r) * factorial(n-r) ;

    return numerator / denomerator ;
}

int main(){
    int n , r;
    cin>>n>>r;

    int ans = nCr(n,r);
    cout<<"nCr is "<<ans<<endl;
}