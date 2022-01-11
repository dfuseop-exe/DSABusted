#include<iostream>
using namespace std;

void print(int &p){
    p = p+1 ;
    cout<<" fn "<<endl;
    cout<<p<<endl;
    cout<<"before "<<&p<<endl;
}

int main(){
    int arr[5] = {1,2,3,4,5};
    cout<<&(arr[1])<<endl;
    cout<<(arr[1])<<endl;
    print(arr[0]);

}