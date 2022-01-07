/*
    321
    321
    321

*/


#include <iostream>
using namespace std ;

int main(){
    int n ;
    cin>>n;

    int row = 1 ;
    while(row <= n){
        int col = 3 ;
        while(col>=1){
            cout<<col;
            col--;
        }
        cout<<endl;
        row++;
    }
}