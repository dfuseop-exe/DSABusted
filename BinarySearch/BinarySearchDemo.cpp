#include<iostream>
using namespace std;

int BinarySearch(int arr[] , int size , int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end - start) / 2 ;

    while(start <= end){
        
        if(arr[mid] == key){
            return mid;
        }
        
        if(key < arr[mid]){
            end = mid-1;
        }

        if(key > arr[mid]){
            start = mid+1;
        }

        mid = start + (end - start) / 2 ;
    }

    return -1;
}

int main(){
    int even[] = {2 , 5 , 7 , 9 , 10 ,15};
    int odd[] = {3 , 8 , 11 , 17 ,20};

    int evenIndex = BinarySearch(even , 6 , 5);
    cout<<"Element 5 is Found at "<<evenIndex<<endl;

     int oddIndex = BinarySearch(odd , 5 , 17);
    cout<<"Element 17 is Found at "<<oddIndex<<endl;
}

