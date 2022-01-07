#include<iostream>
using namespace std;

int main(){
    int arr[3][3] = {{1,2,3} , {4,5,6} , {7,8,9}};

    for(int col = 0; col < 3; col++){
        //if col is odd
        if(col&1){
            for(int row = 3-1; row >= 0; row--){
                cout<<arr[row][col]<<" ";
            }
            cout<<endl;
        }else{
            for(int row = 0; row < 3; row++){
                cout<<arr[row][col]<<" ";
            }
            cout<<endl;
        }
    }
}