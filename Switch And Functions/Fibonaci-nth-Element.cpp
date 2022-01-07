#include<iostream>
using namespace std;

void PrintFibonaci(int n){
    int a = 0 ;
    int b = 1 ;

    for(int i = 0 ; i < n-2; i++){

        int nextNumber = a+b;
        a = b;
        b = nextNumber;

    }
    cout<<b<<" ";
}

int main(){
    int num;
    cin>>num;
    
    PrintFibonaci(num);
} 