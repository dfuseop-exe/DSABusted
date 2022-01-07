/*
    * * * *
      * * *
        * *
          *
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    int row = 1 ;
    while(row <= n){
        //space
        int space = row-1;
        while(space){
            cout<<" ";
            space--;
        }
        
        //star
        int col = n-row+1;
        while(col){
            cout<<"*";
            col--;
        }
        cout<<endl;
        row++;
    }
}