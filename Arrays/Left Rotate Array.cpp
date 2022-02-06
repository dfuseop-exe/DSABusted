#include<iostream>
using namespace std;

int main(){
  int arr [] = {1,2,3,4,5};
  int size = 5 ;
  int temp[5]={0};

  for(int i = 0 ; i < size; i++){
    temp[(size+i-2)%size] = arr[i];
  }
 

  for(int i = 0 ; i < size ; i++){
    cout<<temp[i]<<" ";
  }
}