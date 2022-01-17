#include<iostream>
using namespace std;

int global_variable = 5 ;

void functionA(int a){
    cout<<a<<endl;
    cout<<"Form A "<<global_variable<<endl;
}

int main(){
    int a = 10 ;
    functionA(a);
    cout<<a<<endl;
    cout<<"Form Main "<<global_variable<<endl;
}