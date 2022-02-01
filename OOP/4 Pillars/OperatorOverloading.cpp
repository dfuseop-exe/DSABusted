#include<iostream>
using namespace std;


class A{
    public : 
        int a ;
    
        void operator+ (A &obj){ 
            cout<< this->a - obj.a<<endl;
        }

};

int main(){
    A obj1 ;
    obj1.a = 5 ;

    A obj2 ;
    obj2.a = 7 ;

//caller  passed obj
    obj2 + obj1 ;
}