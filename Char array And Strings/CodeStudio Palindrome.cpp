#include<iostream>
using namespace std;

int checkStart(char ch , int s){
    bool isValid = false ;
    while(!isValid){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        cout<<"rstart "<<s<<endl;
        return s;
        }else{
            isValid = true;
            s++;
        }
    }
    cout<<s<<" startCheck"<<endl;
    return s;
}

int checkEnd(char ch , int e){
    bool isValid = false ;
    while(!isValid){
        if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')){
        cout<<"rend "<<e<<endl;
        
        return e;
        }else{
            isValid = true;
            e--;
        }
    }
    cout<<e<<" startCheck"<<endl;
    return e;
}

bool palindrome(char name[] , int h){
    int s = 0 ;
    int e = h-1;

    int news = checkStart(name[s] , s);
    int newe = checkEnd(name[e] , e);

    while(news<newe){

        if( name[news] != name[newe]){
            return false;
        }else{
            news++;
            newe--;
        }
        
        news = checkStart(name[news] , news);
        newe = checkEnd(name[newe] , newe);
        cout<<"Iteration "<<news<<" "<<newe<<endl;

    }
    return true;
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
    int lenght = getLenght(name);

    cout<<"Is it palindrome ? "<<palindrome(name , lenght)<<endl;
}