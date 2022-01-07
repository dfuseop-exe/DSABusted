#include<iostream>
using namespace std;

bool isEvenOdd(int num1){
   
   // 111 & 1 = 1
   if(num1 & 1){
       //odd
       return false;
   }
   return true;
}

int main(){
    int a ;
    cin>>a;

    if(isEvenOdd(a)){
        cout<<"Even "<<endl;
    }else{
        cout<<"Odd "<<endl;
    }
    
}