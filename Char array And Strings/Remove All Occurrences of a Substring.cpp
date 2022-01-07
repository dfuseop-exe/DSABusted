#include <string.h>
#include <iostream>
using namespace std;

int main(){
    string str = "axxxxyyyyb";
    string part = "xy";

    while(str.length() != 0 && str.find(part) < str.length()){
        str.erase(str.find(part) , part.length());
    }
    cout<<str<<endl;
}