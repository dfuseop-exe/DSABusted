#include <iostream>
#include<string.h>
using namespace std;

void reverse(string s){
  string temp = s;
  int n = temp.length();

  int start = 0;
//i<=n is because of last \0 should be consider 
  for(int i=0;i<=n;i++){

    if(temp[i] == 32 || temp[i] == '\0'){
      
      int end = i-1;

      while(start < end){
        swap(temp[start++] , temp[end--]);
      }
      start = i+1;
    }
  }


    cout<<temp;
  
}

int main() {
  string str = "My Name is Sushant 2418";
  reverse(str);
  return 0;  
} 