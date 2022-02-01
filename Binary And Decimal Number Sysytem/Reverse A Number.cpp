#include<iostream>
#include<climits>
using namespace std;

int main(){
    int n ;
    cin>>n;

    int ans = 0 ;



    while(n != 0){
        int digit = n % 10 ;
        ans = ans*10 + digit;

        if(n < (INT_MIN / 10) || n > (INT_MAX / 10) ){
            return 0;
        }
        n = n / 10;
    }
    cout<<ans;
}


