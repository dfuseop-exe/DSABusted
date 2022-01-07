#include<iostream>
using namespace std;

int countSetBit(int n){

    int counter = 0 ;

    while(n != 0){
        if(n & 1){
            counter++;
        }
        n = n>>1;
    }

    return counter;
}

int main(){
    int num1 , num2 ;
    cin>>num1>>num2;

    int Num1count = countSetBit(num1);
    int Num2count = countSetBit(num2);

    int total = Num1count+Num2count;

    cout<<"Total set bits are "<<total<<endl;
}