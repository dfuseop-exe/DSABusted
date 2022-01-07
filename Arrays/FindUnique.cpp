#include<iostream>
using namespace std;

int FindUnique(int arr[] , int n){
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){
    int arr[100];
    int size;

    cin>>size;

    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    
    int ele = FindUnique(arr,size);
    cout<<ele;
}