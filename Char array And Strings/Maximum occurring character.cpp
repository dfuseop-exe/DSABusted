#include<iostream>
#include<string.h>
using namespace std;

char CountOcc(string s){
    
    int  counter[26] = {0};

    for(int i = 0; i < s.length(); i++){
        char ch  =  s[i];

        int number = -1;
        if(ch >= 'a' && ch <= 'z'){
            number = ch - 'a';
        }else{
            number = ch - 'A';
        }
        counter[number]++;
    }

    int maxCount = -1;
    int ans = 0;

    for(int i = 0; i < 26; i++){
        if(counter[i] > maxCount){
            maxCount = counter[i];
            ans = i;
        }
    }

    return ans+'a';
}

int main(){
    string s = "arr";
    cout<<CountOcc(s)<<endl;
}