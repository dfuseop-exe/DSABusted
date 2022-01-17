#include<iostream>
using namespace std;

void PassByValue(int n){
    n++;
} 

void PassByRef(int &n){
    n++;
} 

int main(){
    int i = 5;
    cout<<"Before " <<i<<endl;
    PassByRef(i);
    cout<<"After " <<i<<endl;
    
} 