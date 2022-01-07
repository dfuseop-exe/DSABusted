/*
    A B C 
    B C D
    C D E
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int row = 1 ;

    while(row<=n){
        int col = 1;
        while(col <= n){
            //123 234 345 ==> row+col-1
            char ch = 64 + row+col-1;
            cout<<ch<<" ";
            col++;
        }
        cout<<endl;
        row++;
    }
}