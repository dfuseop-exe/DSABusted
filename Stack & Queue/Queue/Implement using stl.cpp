#include<queue>
#include<iostream>

using namespace std ;

int main(){
    queue<int> q ;
    q.push(11);
    q.push(32);
    q.push(23);

    cout<<"Size : "<<q.size()<<endl;
    cout<<"isEmpty : "<<q.empty()<<endl;
    cout<<"isEmpty : "<<q.empty()<<endl;
    cout<<"Top : "<<q.front()<<endl;
    cout<<"Rear : "<<q.back()<<endl;
    q.pop() ;
    cout<<"Top : "<<q.front()<<endl;

}