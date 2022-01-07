#include<iostream>
using namespace std;

void largest(int arr[3][3]){
    int ans = -1;
    int index= 0;
    cout << "Printing Sum -> " << endl;
    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }
    
        if(sum > ans){
            ans = sum ;
            index = row+1;
        }
        
    }
    cout << index << " "<<endl;
}

int main(){
    int arr[3][3];
    int sum = 0 ;
    //input
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            cin>>arr[row][col];
        }
    }

    largest(arr);  
}