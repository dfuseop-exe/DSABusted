#include<iostream>
#include<string.h>
using namespace std;


int main(){
    char s1[10] = "Sushant";
    char s2[10] = "Sushant";

    char newArr[10] ;
    strcpy(newArr, s1);
    cout<<newArr<<endl;
    cout<<strcmp(s1,s2)<<endl;
}