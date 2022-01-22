#include<iostream>
using namespace std;

int Sum(int arr[] , int size ){
    //base case
    if(size==0) 
        return 0;

    if(size == 1)
        return arr[0];

    int rem =  Sum(arr+ 1, size - 1);
    int sum = rem + arr[0];
    return sum ;
}

int main(){
    int arr[] = {3,2,5,1,6};
    int size = 5 ;

    int totalSum = Sum(arr , size);
    cout<<totalSum<<endl;
}