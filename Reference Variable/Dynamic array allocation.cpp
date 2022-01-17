#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    //Dynamic array allocation return address of first location store in arr ptr
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        // arr[i] == *(arr+i)
        cin>>*(arr+i);
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }

    delete[] arr;
}