#include<iostream>
using namespace std;

int merge(int arr1[] , int n ,int arr2[] , int m ,int ans[]){
    int i = 0;
    int j = 0;
    int s = n+m;
    

    int k=0 ;
    while( i < n && j < m ){
        if(arr1[i] < arr2[j]){
            ans[k] = arr1[i];
            i++;
            k++;
        }else{
            ans[k] = arr2[j];
            k++;
            j++;
        }
    }

    while(i<n){
        ans[k] = arr1[i];
        i++;
        k++;
    }

    while(j<m){
        ans[k] = arr2[j];
        j++;
        k++;
    }

    for(int i=0 ; i<n+m ; i++ ){
        arr1[i] = ans[i];
    }
}

void print(int ans[] , int n){
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int arr1[8] = {1,3,5,7,9,0,0,0};
    int arr2[3] = {2,4,6} ;
    int ans[8];

    merge(arr1,5,arr2,3,ans);
    print(arr1,8);
}