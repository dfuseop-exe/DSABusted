#include<iostream>
using namespace std;

bool check(int arr[] , int i ){
    //base case
    if(i == 6){
        return true;
    }

    if(arr[i] > arr[i+1])
        return false; ;
    i++;
    
    int ans = check(arr , i);
}

int main(){
    int arr[] = {1,4,6,-8,9,9};
    int i = 0 ;
    bool ans = check(arr , i );
    cout<<ans<<endl;
}