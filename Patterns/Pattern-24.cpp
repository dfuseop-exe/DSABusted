/*
    1 1 1 1
      2 2 2
        3 3
          4
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
        
        //number
        int col = n-row+1;
        while(col){
            cout<<row;
            col--;
        }
        cout<<endl;
        row++;
    }
}