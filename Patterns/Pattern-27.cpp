/*
          1
        2 3
      4 5 6
    7 8 9 10

*/

#include<iostream>
using namespace std;

int main(){
    int n , count = 1;
    cin>>n;

    int row =1 ;
    while(row <= n){
        int space  = n - row;
        while(space){
            cout<<" ";
            space--;
        }

        int col = row;
        while(col){
            cout<<count;
            count++;
            col--;
        }
        cout<<endl;
        row++;
    }

}