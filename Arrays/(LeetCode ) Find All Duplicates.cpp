#include<iostream>
using namespace std;

int main(){
    int arr[] = { 1 , 5 , 3 , 4 , 3 , 5};
    int ans[6] = {0};
    int j=0;

    for(int i = 0 ; i+1 < 6 ; i = i++ ){
        if(arr[i] == arr[i+1]){
            ans[i] = arr[i];
            j++;
            cout<<ans[1]<<" ";
        }
    }

        
    for (int i = 0; i < j; i++)
    {
        cout<<ans[i]<<" ";
    }
    
}