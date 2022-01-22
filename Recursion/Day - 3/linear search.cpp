#include<iostream>
using namespace std;

bool Search(int arr[] , int size , int k){
    //base case
    if(size == 0) 
        return false;

    if(arr[0] == k)
        return true;

    bool remainingPart = Search(arr+1, size-1, k);
    return remainingPart;
}

int main(){
    int arr[] = { 2 , 4 , 1 , 8 , 9 };
    int size = 5;
    int k = 12 ;

    bool ans = Search(arr , size , k);
    cout<<ans<<endl;
}