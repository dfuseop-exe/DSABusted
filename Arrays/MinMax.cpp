#include<iostream>
using namespace std;

int Max(int num[] , int size){
    int max = INT32_MIN;
    for (int i = 0; i < size; i++){
        if(num[i] > max){
            max = num[i];
        }
    }  
    return max;  
}

int Min(int num[] , int size){
    int min = INT32_MAX;
    for (int i = 0; i < size; i++){
        if(num[i] < min){
            min  = num[i];
        }
    }  
    return min;  
}

int main(){
    int size ;
    cin>>size;

    //good practice
    int num[100];

    for(int i = 0 ; i < size ; i++){
        cin>>num[i];
    }

    cout<<"Maximum element  : "<<Max(num , size)<<endl;
    cout<<"Minimum element  : "<<Min(num , size);
}