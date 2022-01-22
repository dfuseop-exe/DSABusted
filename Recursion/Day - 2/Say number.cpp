#include<iostream>
using namespace std;

void sayNumber(int n , string arr[]){
    //base case
    if(n==0)
        return ;

    //processing 
 
    int rem = n % 10;
    n = n / 10;

    sayNumber(n , arr);
    cout<<arr[rem]<<" ";
}

int main(){
    string arr[10] = {"zero","one" , "two" , "three" , "four" , "five" , "six" , "seven" , "eight" , "nine"};
    int n = 12;
    sayNumber(n , arr);
}