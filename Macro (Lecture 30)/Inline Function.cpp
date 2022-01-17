#include<iostream>
using namespace std;

inline int getMax(int a , int b){
    return a > b ? a : b ;
}

int main(){
    int a = 2 ;
    int b = 3 ;

    /* here as it is inline function so function call is replaced with function body like
        getMax(a,b) is replace with return a > b ? a : b ; at compile time

        advantage :- no extra copy memory no function call stack entry
    */
    int ans = getMax(a,b);
    cout<<ans<<endl;
}