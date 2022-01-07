#include<iostream>
using namespace std;

// void reverse(int arr[] , int size){
//     int temp = 0;
//     for (int i=0; i<(size/2); i++){
//         temp = arr[size-i-1];
//         arr[size-i-1] = arr[i];
//         arr[i]=temp;      
//     }
// }

void reverse(int arr[] , int size){
    int start = 0 ;
    int end = size-1;

    while(start<end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main(){
    int arr[6];
    int size = 6;

    for (int i=0; i<6; i++){
        cin>>arr[i];        
    }

    reverse(arr , size);

      for (int i=0; i<6; i++){
        cout<<arr[i]<<" ";        
    }

}