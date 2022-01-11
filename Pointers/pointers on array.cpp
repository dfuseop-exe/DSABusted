#include<iostream>
using namespace std;

int main(){

    // int *ptr = arr;
    // int *ptr2 = arr+5;
    // int *ptr3 = arr+4;
    // cout<<*ptr<<endl;
    // cout<<ptr3<<endl;
    // cout<<ptr2<<endl;

    // int *p = arr;
    // cout<<" chalaki "<<(0[arr])<<endl;
    // cout<<" chalaki "<<(2[arr])<<endl;

    // //both gaves address of arr 
    // cout<<&(arr)<<endl;
    // cout<<arr<<endl;


    int arr[] = {41,22,37,44,53};
    int *ptr = arr;

    cout<<ptr<<endl;
    ptr =ptr+1; // add 4 as interger 4 bytes
    cout<<ptr<<endl;


}