

#include<iostream>
using namespace std;

int pivotElement(int arr[] , int size){
    int start = 0 ;
    int end = size - 1;
    int mid = start + (end - start) / 2 ;

    while(start < end){
        //check Ist line var aahe ka
        if(arr[mid] >= arr[0]){
            start = mid + 1;
        }
        //check II line var aahe ka asel tr end = mid karaych 
        else{
            end = mid;
        }
        mid = start + (end - start) / 2 ;
    }
    return start ;
}

bool BinarySearch(int arr[] , int s , int e , int key){
    int start = s;
    int end = e;
    int mid = start + (end - start) / 2 ;

    while(start <= end){
        
     
        if(arr[mid] == key){
            return true;
        }
        
        if(key < arr[mid]){
            end = mid-1;
        }

        if(key > arr[mid]){
            start = mid+1;
        }

        mid = start + (end - start) / 2 ;
    }

    return false;
}

int main(){
    int arr[] = {7 , 9 , 1 , 2 , 3};
    int pivot = pivotElement(arr , 5);
    cout<<"Pivot element is "<<arr[pivot]<<endl;
    int key = 11;
    
     if(arr[pivot]<=key && key<=5-1){

         //  For second Line
         if(BinarySearch(arr , pivot , 5-1 , key)){
             cout<<"Found "<<endl;
         }else{
         cout<<"Not FOund "<<endl;
         }

         
        
     }else{
        //  For First Line
         if(BinarySearch(arr , 0 , pivot , key)){
             cout<<"Found "<<endl;
         }else{
             cout<<"Not FOund "<<endl;
         }
     }

    //Or
    //    if(arr[0] < k &&  k > arr[pivot]){
    //         ans = binarySearch(arr , 0 , (pivot-1) , k);
    //     }else{
    //         ans = binarySearch(arr , pivot , e , k);
    //     }
            
}



