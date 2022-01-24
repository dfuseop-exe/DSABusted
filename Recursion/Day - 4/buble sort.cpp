#include<iostream>
using namespace std;

void sortBuble(int arr[] , int n){ 
    //base case 
    if(n == 0 || n == 1){
        return ;
    }

    for(int i = 0; i < n-1;i++){
        if(arr[i] > arr[i+1]){
            swap(arr[i] , arr[i+1]);
        }
    }

    sortBuble(arr , n-1);
}

int main(){
    int arr[] = {7,4,3,9,5};
    int size = 5;
    sortBuble(arr , size);
    
    for(int i = 0; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}