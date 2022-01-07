#include<iostream>
using namespace std;

void Alterswap(int arr[] , int size ){
    for (int i = 0; i+1 < size; i+=2){
        swap(arr[i],arr[i+1]);
    }
}

int main(){
    int size;
    cin>>size;

    int arr[size];

    for(int i = 0 ; i < size ; i++ ){
        cin>>arr[i];
    }

     Alterswap(arr,size);

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";        
    }
}
