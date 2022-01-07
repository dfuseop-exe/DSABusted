#include<iostream>
using namespace std;

bool isPosible(int arr[] , int n , int m , int  mid){
    int studentCount = 1;
    int pageCount = 0;

    for(int i = 0 ; i< n ; i++){
        if(pageCount + arr[i] <= mid){
            pageCount += arr[i];
        }else{
            studentCount++;
            //check student count jada toh nahi hua ? and current pages mid se jada toh nahi ?
            if(studentCount > m || arr[i] > mid){
                return false;
            }
            pageCount = arr[i];
        }
    }
    return true;
}

int main(){
    int arr[] = {5,5,5,5};
    int student = 2;
    int book = 4 ;

    int start = 0 ;
    int sum = 0 ;

    for(int i = 0 ; i < book ; i++){
        sum += arr[i];
    }

    int ans = -1;
    int end = sum;
    int mid = start + (end - start) / 2 ;

    while(start <= end){
        if(isPosible(arr,book,student,mid)){
            ans = mid ;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
        mid = start + (end - start) / 2 ;
    }
    cout<< ans<<endl;
}
