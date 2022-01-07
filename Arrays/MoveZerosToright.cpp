#include<iostream>
using namespace std;

int main(){
    int arr[] = {0,1,0,3,12,0};
    int n = 6;

    int nonZeroPtr = 0;
    
    for(int i = 0; i < n; i++){
        if(arr[i] != 0){
            cout<<arr[i]<<" "<<arr[nonZeroPtr]<<endl;
            swap(arr[i],arr[nonZeroPtr]);
            nonZeroPtr++;
        }
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}
