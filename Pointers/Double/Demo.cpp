#include<iostream>
using namespace std;

int main(){
    int i = 5;
    int* ptr1 = &i;
    int** ptr2 = &ptr1;


    //for printing i content
    cout<<i<<endl;
    cout<<*ptr1<<endl; 
    cout<<**ptr2<<endl; 

    //for printing ptr1 content
    cout<<&i<<endl;
    cout<<ptr1<<endl;
    cout<<*ptr2<<endl;

    //for printing ptr2 content
    int* temp = &i;
    cout<<&ptr1<<endl;
    cout<<ptr2<<endl;

}