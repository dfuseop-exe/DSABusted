#include<iostream>
using namespace std;

void merge(int arr[] , int s , int e){
    int mid =  s + (e-s)/2 ;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];


    int index = s;

    //copy elements

    for(int i = 0; i < len1; i++){
       arr1[i] = arr[index++]; 
    }

    //copy elements
    index = mid+1;
    for(int i = 0; i < len2; i++){
       arr2[i] = arr[index++]; 
    }

    //merge elements
    index = s;
    int i = 0 , j = 0 ;
    while(i < len1 && j < len2){
        if(arr1[i] < arr2[j]){
            arr[index++] = arr1[i++];
        }else{
            arr[index++] = arr2[j++];
        }
    }

    while(i < len1){
        arr[index++] = arr1[i++];
    }

    while(j < len2){
        arr[index++] = arr2[j++];
    }

    delete []arr1;
    delete []arr2;
}

void mergeSort(int arr[] , int s , int e){
    //base case for
    if(s >= e){
        return ;
    }

    int mid = s + (e-s)/2 ;

    mergeSort(arr , s , mid) ;
    mergeSort(arr , mid+1 , e) ;

    merge(arr,s,e);
}

int main(){
    int arr[] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15 ;
            //start nd end pass
    mergeSort(arr,0,n-1);

    for(int i=0;i<15;i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}