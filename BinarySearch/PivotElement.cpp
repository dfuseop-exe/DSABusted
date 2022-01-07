#include<iostream>
using namespace std;

int pivotElement(int arr[] , int size){
    int start = 0 ;
    int end = size - 1;
    int mid = start + (end - start) / 2 ;

    while(start < end){
        //check Ist line var aahe ka
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        //check II line var aahe ka asel tr end = mid karaych 
        else{
            end = mid;
        }
        mid = start + (end - start) / 2 ;
    }
    return start ;
}

int main(){
    int arr[] = {7 , 9 , 1 , 2 , 3};
    int pivot = pivotElement(arr , 5);
    cout<<"Pivot element is "<<arr[pivot]<<endl;
}