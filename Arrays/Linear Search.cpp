#include<iostream>
using namespace std;

bool LenearSearch(int arr[] , int size , int ele){
    bool found = false;
    for (int i = 0; i < size; i++){
        if (arr[i] == ele)
        {   
            found = true ;
            break;
        }
    }
    return found;
}

int main(){
    int size;
    cin>>size;

    int arr[100];

    for(int i = 0 ; i < size ; i++ ){
        cin>>arr[i];
    }

    cout<<"Enter Value to be search "<<endl;
    int ele = 0;
    cin>>ele;


    if(LenearSearch(arr,size,ele) == true){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
}