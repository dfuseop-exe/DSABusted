/*
    1
    23
    345
    4567
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int row = 1 ;
    while(row<=n){
        int col=1;
        int counter = row ;
        while(col<=row){
            cout<<counter;
            col++;
            counter++;
        }
        cout<<endl;
        row++;
    }
}