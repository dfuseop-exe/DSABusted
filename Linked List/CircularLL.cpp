#include<iostream>
using namespace std;

class Node{
    public:
        int data ;
        Node* next ;

        Node(int value){
            this-> data = value;
            this-> next = NULL ;
        }

        ~Node(){
            int value = this->data ;
            if(this-> next != NULL){
                delete next;
                next = NULL;
            }
        }
};

void insertNode(Node* &tail , int element , int data){
    
    //if tail == NULL means no node is present
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode-> next = newNode;
    }else{
        //assume it contain at least one node
        Node* ptr = tail ;

        while(ptr-> data != element){
            ptr = ptr-> next ;
        }
        
        //leaving loop means we are on data element
        Node* newNode = new Node(data);
        newNode-> next = ptr-> next ;
        ptr-> next = newNode ;

    }
}

void deleteNode(Node* &tail , int element){
    //if list is empty 
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }else{
        //element is present
        //assume it contains value element node
        Node* prev = tail;
        Node* curr = prev-> next ;

        while(curr-> data != element){
            prev = curr ;
            curr = curr-> next ;
        }

        prev-> next = curr-> next ;

        //if 1 node is present
        if(curr == prev){
            tail = NULL;
        }else if(tail == curr){
            // if >=2
            tail = prev ;   
        }

        curr-> next = NULL;
        delete curr ;
    }
}

void traverse(Node* tail){
    //create ptr for traverse
    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty hai "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
}

int main(){

    Node* tail = NULL;
    insertNode(tail , 1 , 10);
    traverse(tail);
    insertNode(tail , 10 , 20);
    traverse(tail);
    insertNode(tail , 20 , 30);
    traverse(tail);
    insertNode(tail , 20 , 25);
    traverse(tail);
    insertNode(tail , 30 , 35);
    traverse(tail);
    
    deleteNode(tail,25);
    traverse(tail);
    deleteNode(tail,35);
    traverse(tail);
    deleteNode(tail,10);
    traverse(tail);
    deleteNode(tail,30);
    traverse(tail);
    deleteNode(tail,20);
    traverse(tail);
    
}