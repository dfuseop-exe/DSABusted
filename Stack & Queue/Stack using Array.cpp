#include<iostream>
using namespace std;

class Stack {
    public : 
        //properties
        int *arr ;
        int size ;
        int top ;
        
        //Constructor
        Stack(int size){
            this->size = size ;
            top = -1 ;
            arr = new int[size] ;
        }
        
        //Behaviour
        void push(int val){
            if(size - top > 1){
                top++ ;
                arr[top] = val ;
            }else{
                cout<<"Stack Overflow"<<endl ;
            }
        }

        void pop(){
            if(top >= 0){
                top-- ;
            }else{
                cout<<"Stack Underflow"<<endl ;
            }
        }

        int getPeak(){
            if((top >= 0) && (top < size)){
                cout<<"Peak: "<<arr[top]<<endl ;
            }else{
                cout<<"Stack is empty "<<endl;
            }
        }

        bool isEmpty(){
            if(top == -1){
                cout<<"Stack is empty "<<endl ;
            }else{
                cout<<"Stack is not empty "<<endl ;
            }
        }

};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(5);
    
    st.pop();
    st.pop();
    st.pop();

    st.isEmpty();
    st.getPeak();
} 
