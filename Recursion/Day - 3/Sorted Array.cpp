//type 2 -YT

#include<iostream>
using namespace std;

bool check(int arr[] , int size ){
    //base case
    if(size == 0 || size == 1)
        return true;
    
    if(arr[0] > arr[1])
        return false; 
    
    int ans = check(arr+1 , size - 1);
}

int main(){
    int arr[] = {1,4,6,8,9,9};
    int size = 6;
    bool ans = check(arr , size);
    cout<<ans<<endl;
}