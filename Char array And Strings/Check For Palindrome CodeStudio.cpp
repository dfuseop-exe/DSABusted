#include<iostream>
#include<string.h>
using namespace std;

bool valid(char ch){
        if((ch >= 'a' && ch<='z') || (ch >= 'A' && ch<='Z') || (ch >= '0' && ch<='9')){
            return 1;
        }
        return 0;    
}

char toLowerCase(char ch){
    	char temp;
        if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <='9')){
            return ch;
        }else{
            temp = ch -'A' + 'a';
        }
        return temp;
}

 bool palindrome(string a){
        int s = 0 ;
        int e = a.length()-1;

        while(s<e){
            if(a[s] != a[e]){
                return false;
            }else{
                s++;
                e--;
            }
        }
        return true;
    }

int main()
{
    string s = "a$@b#c@b#a";
 	string temp = "";
     int len = s.length();
     cout<<"len: "<<len<<endl;
    for(int i=0;i<len;i++){
        if(valid(s[i])){
            char item = toLowerCase(s[i]);
            temp.push_back(item);
        }
    }
    
    cout<<temp<<endl;
    cout<<palindrome(temp);
}