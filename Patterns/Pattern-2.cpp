/*
    1111
    2222
    3333
    4444
*/


#include <iostream>
using namespace std ;

int main(){
    int n ;
    cin>>n;

    int row  = 1;
    while(row <= n){
        int col = 1;
        while(col <=n){
            cout<<row;
            col++;
        }
        cout<<endl;
        row++;
    }
}