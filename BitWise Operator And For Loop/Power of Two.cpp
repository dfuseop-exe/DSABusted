#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n = 14;

    for(int i = 0; i < n; i++){
        int ans = pow(2,i);

        if(ans == n){
            cout<<"True";
        }
    }
    
    cout<<"false";
}