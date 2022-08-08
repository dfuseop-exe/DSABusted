#include<iostream>
using namespace std;
int minJumps(int arr[], int n){
        int steps = 0 ;
        int curr = 0 ;
        while(curr < n){
            steps++ ;
            cout<<curr<<" and steps  "<<steps<<" and arr[curr] "<<arr[curr]<<endl ;
            curr = curr +  arr[curr] ;

            if(arr[curr] >= n){
                cout<<"IN"<<endl ;
                return steps  ;
            }
           
        }
        
        return steps  ;
    }
int main(){
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}  ;
    int steps = minJumps(arr , 11) ;
    cout<<endl<<"Ans is " <<steps ;
}