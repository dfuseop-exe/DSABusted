#include<iostream>
using namespace std;

int main(){
    int col = 3 , row = 3;
    int arr[row][col] = {{1,2,3} , {4,5,6} , {7,8,9}};
    int key = 0;
    bool found = false;
    int start = 0 , end = (row*col)-1;
    int mid = start + (end - start) / 2 ;
    
    while(start <= end){
        int element = arr[mid/col][mid%col];
        cout<<mid;
        if(element == key){
            found = true;
            break;
        }else if(key > element ){
            start = mid + 1;
        }else{
            end = mid -1 ;
        }
        mid = start + (end - start) / 2 ;
    }

    if(found){
        cout<<"found"<<endl;
    }else{
        cout<<"Not Found"<<endl;

    }
}