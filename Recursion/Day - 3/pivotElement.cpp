#include<iostream>
using namespace std;

int pivotElement(int arr[] , int s , int e){
    //base case 
    if(s == e){
        return s;
    }

    int mid = s + (e-s)/2 ;

    if(arr[mid] >= arr[0]){
        return pivotElement(arr , mid+1 , e);
    }else{
        return pivotElement(arr , s , mid);
    }
}

int main(){
    int arr[] = {7 , 1  , 2 , 3};
    int pivot = pivotElement(arr , 0 , 4);
    cout<<"Pivot element is "<<arr[pivot]<<endl;
}