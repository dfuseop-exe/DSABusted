#include<iostream>
using namespace std;

void PrintSumRow(int arr[3][3]){
    cout << "Printing Sum -> " << endl;
    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[row][col];
        }
        cout << sum << " "<<endl;
    }
}

void PrintSumCol(int arr[3][3]){
    cout << "Printing Sum -> " << endl;
    for(int row=0; row<3; row++) {
        int sum = 0;
        for(int col=0; col<3; col++) {
            sum += arr[col][row];
        }
        cout << sum << " "<<endl;
    }
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

    PrintSumRow(arr);
    PrintSumCol(arr);
    
}