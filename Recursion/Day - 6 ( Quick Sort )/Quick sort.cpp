#include<iostream>
using namespace std;

int partition(int arr[] , int s , int e){
    
    //take pivot as first element
    int pivot = arr[s];
    int count = 0 ;

    //start from s+1 to last element of arr for checking smaller element count end is already n-1 is passed
    for(int i= s+1 ; i<=e ;i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    //we got right index for arr[s];
    int pivotIndex = s + count ;
    swap(arr[s] , arr[pivotIndex]);


    //now check for a > | a | a <
    //take pointers for partition algorithm
    int i = s , j = e ;

    //for checking elements are present or not on both side
    while(i < pivotIndex && j > pivotIndex){
        
        while(arr[i] <= arr[pivotIndex]){
            i++;
        }

        while(arr[j] > arr[pivotIndex]){
            j--;
        }


        //we are on that point where arr[i] > arr[j] so swap
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i] , arr[j]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[] , int s , int e){

    //base case elements are 1 or 0
    if(s >= e){
        return ;
    }

    // make partition of array
    int p = partition(arr , s ,e);


    //sort left 
    quickSort(arr , s , p-1);

    //sort right 
    quickSort(arr , p+1 , e);
}


int main(){
    int arr[] = {8,8,4,7,6,1,2,8};
    int n = 8;

    quickSort(arr , 0 , n-1);

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}