#include<iostream>
using namespace std;

int peakIndex(int arr[] , int size){
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start)/2 ;
    int ans = -1;
    
    while(start < end){

        if(arr[mid] < arr[mid+1]){
            start = mid+1;
        }
        else{
            end = mid;
        }
        mid = start + (end - start)/2 ;
    }

    return mid;
}

int main(){
    int arr[] = { 1 , 2 , 3 , 5 , 3 , 2 , 1};
    int peak = peakIndex(arr , 7);
    cout<<"Peak index is " << peak<<endl<<"element present is "<<arr[peak]<<endl; 
}