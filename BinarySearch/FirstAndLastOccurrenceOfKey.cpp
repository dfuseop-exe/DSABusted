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
    int arr[] = { 0, 0 ,1 ,1 ,2 ,2, 2, 2};

    int first = firstOccurrence(arr , 2 , 8);
    cout<<"First Occurrence Of 3 is At Index "<<first<<endl;

    int last = LastOccurrence(arr , 2 , 8);
    cout<<"Last Occurrence Of 3 is At Index "<<last<<endl;
}