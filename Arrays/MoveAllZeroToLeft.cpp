#include<iostream>
using namespace std;

int main(){
    int arr[] = {0,1,0,3,12,0};
    int n = 6;

    int nonZeroPtr = n-1;

    for(int i = n-1; i >= 0; i--){
        if(arr[i] != 0){
            swap(arr[i],arr[nonZeroPtr]);
            nonZeroPtr--;
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}