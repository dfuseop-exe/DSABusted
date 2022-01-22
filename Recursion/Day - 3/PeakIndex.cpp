#include<iostream>
using namespace std;

int peakIndex(int arr[] ,int s , int e){
    //base case
    if(s == e){
        return s;
    }

    int mid = s + (e-s)/2;

    if(arr[mid] < arr[mid+1]){
        return peakIndex(arr , mid+1 , e );
    }else{
        return peakIndex(arr , s , mid);
    }
}


int main(){
    int arr[] = { 1 , 2 , 3 , 5 , 8 , 2 , 1};
    int peak = peakIndex(arr , 0 , 7);
    cout<<"Peak index is " << peak<<endl<<"element present is "<<arr[peak]<<endl; 
}