#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3};
    int n = 3;
    int counter = 0;

    for(int i = 1 ; i < n ; i++){
      if(arr[i]<arr[i-1]){
        counter++;
      }
    }

    if(arr[n-1] > arr[0]){
      counter++;
    }

    if(counter<=1){
      cout<<"True"<<endl;
    }else{
      cout<<"false"<<endl;
    }
}