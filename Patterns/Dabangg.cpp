/*
    

*/

#include<iostream>
using namespace std;

int main(){
    int n , count = 1;
    cin>>n;

    int row = 1 ;
    while(row <= n){
        int first = n-row+1;
        while(first){
            cout<<first;
            first--;
        }

        
    }
}
