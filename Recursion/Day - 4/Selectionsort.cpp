#include <iostream>
using namespace std;

void Selectionsort(int arr[] , int idx , int size){
    //base case: 
     //base case
        if(idx == size)
            return;

        int smallestIdx = idx; // take curr idx element as smallest

        for(int i = idx + 1; i < size; i++){
            if(arr[smallestIdx] > arr[i]) // found another smallest element than arr[smallestIdx]
                smallestIdx = i; // update the smallestIdx val
        }

        //place smallest element found at idx
        int temp = arr[idx];
        arr[idx] = arr[smallestIdx];
        arr[smallestIdx] = temp;

        for(int i = 0; i < size ; i++){
            cout<<arr[i]<<" ";    
        }   
        cout<<endl;

        // one part Done recursion will do other work;
        Selectionsort(arr , idx + 1 , size);
}

int main(){
    int arr[] = { 5, 1,3,2};
    int size = 4 ;

    Selectionsort(arr , 0 , size);

    for(int i = 0; i < size ; i++){
        cout<<arr[i]<<" ";    
    }
}