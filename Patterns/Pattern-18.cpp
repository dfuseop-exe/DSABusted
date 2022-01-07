/*
    A
    BC
    DEF
    GHIJ
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int row = 1 ;
    int count = 1;
    while(row <= n){
        int col= 1 ;
        while(col<=row){
            char ch = 64+count;
            cout<<ch;
            count++;
            col++;
        }
        cout<<endl;
        row++;
    }

}