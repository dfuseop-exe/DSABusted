#include<iostream>
using namespace std;

int firstOccurrence(int arr[] , int key , int size){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2 ;
    int ans = -1;

    while(start <= end){
        if(arr[mid] == key){
            ans = mid;
            end = mid-1;
        }else if(arr[mid] < key){
            start = mid + 1;
        }else if(arr[mid] > key){
            end = mid-1 ;
        }
        mid = start + (end-start)/2 ;
    }

    return ans ;
}


int LastOccurrence(int arr[] , int key , int size){
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2 ;
    int ans = -1;

    while(start <= end){
        if(arr[mid] == key){
            ans = mid;
            start = mid+1;
        }else if(arr[mid] < key){
            start = mid + 1;
        }else if(arr[mid] > key){
            end = mid-1 ;
        }
        mid = start + (end-start)/2 ;
    }

    return ans ;
}

int main(){
    int arr[] = { 0, 1 ,1 ,1 ,1 ,2, 2, 2};

    int first = firstOccurrence(arr , 1 , 8);
    int last = LastOccurrence(arr , 1 , 8);
    int total = last - first + 1;
    cout<<"Total Occurrence Of 1 is "<<total<<endl;
}