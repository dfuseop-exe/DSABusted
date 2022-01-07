#include<iostream>
#include<string.h>
using namespace std;

int checkEqual(int a[] , int b[]){
    for(int i=0; i<26;i++){
        if(a[i]!=b[i]){
            return false; 
        }
    }
    return true;
}

bool findPermutation(){
    string s1 = "ab";
    string s2 = "eidbaooo";

    //count s2 characters occurrencce in count array
    int count1[26] = {0};
    for(int i=0; i<s1.length(); i++){
        int index = s1[i] - 'a';
        count1[index]++; 
    }   

    // for(int i=0; i<26; i++){
    //     cout<<count1[i]<<" ";
    // }
    // count1 array for ab occurrence
    // 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 

    //here we check in first window that is [e i]
    int count2[26] = {0};
    int window = s1.length();
    int i=0;
    for(; (i<window) && (i<s2.length()); i++){
        int index = s2[i] - 'a';
        count2[index]++;
    }

    //after first window we get all occurrences in first window chars that is [e i]
    // 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

    // now check if count1 and count2 are equal then it means permutation exists
    // so check 

    if(checkEqual(count1, count2)){
        return true;
    } 

    //now change thw window by incrementing i in
    // i<s2.length() it is bcause i is like ptr on s2 i should be alwasy less than lenght so it means it is in bitween
    // now i is indicating on window+1 index that is new char
    while(i<s2.length()){
        //incrementing new index
        int newChar = s2[i] - 'a';
        count2[newChar]++;
        //decrement old index
        int oldChar = s2[i - window] - 'a';
        count2[oldChar]--;

        // and again check for new window
        if(checkEqual(count1, count2)){
            return true;
        } 
        
        i++;
    }

    return false;
}

int main(){
    int check = findPermutation();
    cout<<check<<endl;
}