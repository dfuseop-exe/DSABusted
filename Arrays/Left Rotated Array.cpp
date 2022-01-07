#include<iostream>
using namespace std;

int main(){

    //remaining

    int arr[] = {1,2,3,4,5};
    int n = 5;
    int times = 2;
    int temp[5]={0};

    

    for(int i=0; i< n; i++){
        int tIndex = (i-times);
        int fIndex = tIndex % n ;
        temp[fIndex] = arr[i];   
        cout<<fIndex<<" check "<<tIndex<<endl;
    }

    for(int i=0; i<n; i++){
        cout<<temp[i]<<endl;
    }
}