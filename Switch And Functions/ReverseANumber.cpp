#include<iostream>
using namespace std;

int main(){
    int n ;
    cin>>n;

    int digit = 0 , ans = 0 ;
    while(n){
        digit = n % 10;
        ans =  (ans * 10) + digit;
        n = n/10;
    }
    cout<<ans<<endl;
}