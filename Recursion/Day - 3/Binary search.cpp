#include <iostream>
using namespace std;

bool BinarySearch(int arr[] , int s , int e , int k){
    //base case
    if(s > e)
        return false;
    
    int mid = s + (e-s)/2;

    if(arr[mid] == k)
        return true;

    if(arr[mid] > k){
        BinarySearch(arr, s , mid-1 , k);
    }else{
        BinarySearch(arr, mid+1 , e , k);
    }
}

int main(){
    int arr[] = {1,4,6,8,9,9};
    int size = 6;
    int k = 0 ;
    bool ans = BinarySearch(arr , 0 , size , k);
    cout<<ans<<endl;
}