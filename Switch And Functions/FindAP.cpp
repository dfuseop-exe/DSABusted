#include<iostream>
using namespace std;

int findAP(int n){
    return ( 3 * n) + 7 ;
}

int main(){
    int num;
    cin>>num;

    int ans = findAP(num);
    cout<<ans;
}