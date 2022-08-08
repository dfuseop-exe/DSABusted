#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int> pq ;

    pq.push(10) ;
    pq.push(23) ;
    pq.push(12) ;
    pq.push(8) ;

    cout<<"Largest element in list is : "<<pq.top()<<endl ;

    pq.pop() ;
    cout<<"Largest element in list is : "<<pq.top()<<endl ;

    cout<<"isEmpty : "<<!pq.empty()<<endl ;
    cout<<"Size : "<<pq.size()<<endl ;
    

    priority_queue<int , vector<int> , greater<int> > minheap ; 

    minheap.push(23) ;
    minheap.push(12) ;
    minheap.push(10) ;
    minheap.push(8) ;

    cout<<"smallest element in list is : "<<minheap.top()<<endl ;

    minheap.pop() ;
    cout<<"smallest element in list is : "<<minheap.top()<<endl ;

    cout<<"isEmpty : "<<!minheap.empty()<<endl ;
    cout<<"Size : "<<minheap.size()<<endl ;
}