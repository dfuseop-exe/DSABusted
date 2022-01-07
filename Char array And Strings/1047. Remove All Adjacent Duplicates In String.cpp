#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string input = "azxxzy";
    string ans = "";

    //for looping over the input
    for(int i = 0 ; i < input.size() ; i++){
        if( ans.size() == 0 ){
            ans.push_back(input[i]);
        }
        else if(input[i] != ans.back()){
            ans.push_back(input[i]);
        }
        //it means they are same then remove last element from ans and also not stote current element in ans
        else{
            ans.pop_back(); //it will remove last element from ans
        }
    }

    cout<<ans<<endl;
}