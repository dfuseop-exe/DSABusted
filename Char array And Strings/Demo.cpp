#include<iostream>
using namespace std;

char LowerCase(char ch){
    char temp;
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }else{
        temp = ch -'A' + 'a';
    }
    return temp;
}

bool palindrome(char name[] , int h){
    int s = 0 ;
    int e = h-1;

    while(s<e){
        if(LowerCase(name[s]) != LowerCase(name[e])){
            return false;
        }else{
            s++;
            e--;
        }
    }
    return true;
}

bool palindromeS(char name[] , int h){
    int s = 0 ;
    int e = h-1;

    while(s<e){
        if(name[s] != name[e]){
            return false;
        }else{
            s++;
            e--;
        }
    }
    return true;
}

void reverse(char name[] , int size){
    int s = 0 ;
    int e = size-1;

    while(s<e){
        swap(name[s++] , name[e--]);
    }
}

int getLenght(char name[]){
    int counter = 0 ;
    for(int i = 0; name[i] != '\0' ; i++){
        counter++;
    }
    return counter;
}

int main(){
    char name[20];
    
    cout<<"Enter Your Name "<<endl;
    cin>>name;

    // name[2] = '\0';

    int lenght = getLenght(name);

    cout<<"Your name is "<<name<<" with lenght is "<<lenght<<endl;
    reverse(name , lenght);
    cout<<"reverse string is "<<name<<endl;
    cout<<"Is it palindrome (Casesensative) ? "<<palindromeS(name , lenght)<<endl;
    cout<<"Is it palindrome ? "<<palindrome(name , lenght)<<endl;
}