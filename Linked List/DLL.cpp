#include<iostream>
using namespace std;

class Node {
    public :
        Node* next ;
        Node* prev ;
        int data ;

        Node(int value){
            this-> next = NULL;
            this-> prev = NULL;
            this-> data = value ;
        }

        ~Node() {
            int value = this-> data ;
            if(next != NULL){
                delete next ;
                next = NULL;
            }
            cout<<"Memory deallocate memory for "<<value<<endl;
        }
};

void insertAtHead(Node* &head , Node* &tail , int value){
    Node* newNode = new Node(value);
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        
        newNode-> next = head;
        head-> prev = newNode;
        head = newNode;
    }
}

void insertAtTail(Node* &tail ,Node* &head , int value){
    Node* newNode = new Node(value);

    if(tail == NULL){
        tail = newNode;
        head = newNode;
    }else{
        tail-> next = newNode;
        newNode-> prev = tail;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head , Node* &tail , int position , int value){
    Node* newNode = new Node(value);

    if(position == 1){
        insertAtHead(head,tail,value);
        return ;
    }

    int cnt = 1 ;
    Node* temp = head ;

    while(cnt < position-1){
        temp = temp-> next ;
        cnt++;
    }

    if(temp-> next == NULL){
        insertAtTail(tail,head,value);
        return ;
    }

    newNode-> next = temp-> next ;
    newNode-> prev = temp;
    temp-> next = newNode; 
}


void deleteNode(Node* &head , Node* &tail , int position){
    if(position == 1){
        Node* temp = head ;
        temp->next->prev = NULL;
        head = temp-> next ;
        temp-> next = NULL ;
        delete temp;
    }else{
        //any middle or last node
        int cnt = 1 ;
        Node* temp = head ;
        Node* curr = head ;

        while(cnt < position-1){
            temp = temp-> next ;
            curr = curr-> next ;
            cnt++;
        }

        curr = curr-> next ;


        if(curr-> next == NULL){
            tail = temp ;
        }

        temp-> next = temp-> next-> next ;
        
        curr-> next = NULL ;
        curr-> prev = NULL ;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp-> next ;
    }cout<<endl;
}

void getLength(Node* &head){
    int cnt = 0 ;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp-> next ;
    }
    cout<<"Length: "<<cnt<<endl;
}


int main(){

    Node* head = NULL;
    Node* tail = NULL;
    
    insertAtTail(tail,head,1);
    insertAtPosition(head,tail,1,200);
    print(head);
    insertAtHead(head,tail,2);
    print(head);
    insertAtHead(head,tail,5);
    print(head);
    insertAtTail(tail,head,20);
    print(head);
    insertAtPosition(head,tail,4,100);
    print(head);
    deleteNode(head,tail,1);
    print(head);

    cout<<"Head "<<head->data<<endl;
    cout<<"Tail "<<tail->data<<endl;

}