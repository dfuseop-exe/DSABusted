#include<iostream>
using namespace std;

int fact(int n){

    //base condition
    if(n == 0) return 1;

    int smallFunction = fact(n-1);
    return 2 * smallFunction;
}

int main(){
    int n = 3;
    cout<<fact(n)<<endl;
}