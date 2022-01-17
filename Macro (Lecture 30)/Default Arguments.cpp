#include<iostream>
using namespace std;

void print(int arr[] , int s=0){
    for(int i=s; i < 5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int start = 2;

    print(arr , start);
    print(arr);
}