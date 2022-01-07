#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string s = "Coding Ninjas Is A Coding Platform";
    
    string newString = "";
    for(int i = 0; i<s.length(); i++){
        if(s[i] == ' '){
            newString.push_back('@');
            newString.push_back('4');
            newString.push_back('0');

        }else{
            newString.push_back(s[i]);
        }
    }

    cout<<newString<<endl;
}