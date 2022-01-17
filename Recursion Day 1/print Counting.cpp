#include<iostream>
using namespace std;

int PrintCount(int n){

    //base condition
    if(n == 1) return 1;
    cout<<n<<endl;
    PrintCount(n-1);
}

int main(){
    int n = 5;

    cout<<PrintCount(n)<<endl;
}