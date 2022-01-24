#include<iostream>
using namespace std;

int checkPalindrome(string str , int i){
    //base case
    if(i > str.length()-i-1){  
        return 1;
    }
    //processing
    if(str[i] == str[str.length()-i-1]){
        i++;
        return checkPalindrome(str , i );
    }else{
        return 0;
    }

}

int main(){
    string name = "abbcbba";
    int ans = checkPalindrome(name , 0);
    cout << ans << endl;
}

