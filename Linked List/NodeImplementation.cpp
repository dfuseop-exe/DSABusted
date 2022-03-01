#include<iostream>
using namespace std;

class Node {
    public :
        int data ;
        Node* next ;

    Node(int value){
        this-> data = value;
        this-> next = NULL ;
    }

    ~Node(){
        
        
    }
};

//insert At First Position
void insertAtHead(Node* &head , int data){
    //create new node
    Node* newNode = new Node(data);

    newNode-> next = head ;
    head = newNode ;
}

//insert At Last Position
void insertAtTail(Node* &tail , int data){
    //create new node
    Node* newNode = new Node(data);

    tail-> next = newNode;
    tail = newNode ;
}

void insertAtPosition(Node* &tail , Node* &head , int position , int data){
    //create new node
    Node* newNode = new Node(data);

    if(position == 1){
        insertAtHead(head,data);
        return ;
    }

    int cnt = 1 ;
    Node* temp = head ;

    while(cnt < position-1){
        temp = temp-> next ;
        cnt++;
    }

    if(temp-> next == NULL){
        insertAtTail(tail,data);
        return ;
    }

    newNode-> next = temp-> next ;
    temp-> next = newNode ;
}

int deleteNode(Node* &tail ,Node* &head , int position){
    //first node
    if(position == 1){
        Node* curr = head ;
        head = head-> next ;

        curr-> next = NULL ;
        delete curr ;
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
            cout<<"Focuse "<<curr-> data<<endl;
            tail = temp ;
        }

        temp-> next = temp-> next-> next ;
        
        curr-> next = NULL ;
        delete curr;
    }
}

void print(Node* &head){
    Node* temp = head ;

    while(temp != NULL){
        cout<<temp-> data<<" ";
        temp = temp-> next ;
    }cout<<endl;
}

int main(){
    Node* node1 = new Node(20);
    
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail , 30);
    insertAtTail(tail , 40);
    insertAtHead(head , 10);
    insertAtPosition(tail ,head , 4 , 35);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
    deleteNode(tail ,head , 3);
    print(head);
    cout<<"head "<<head->data<<endl;
    cout<<"tail "<<tail->data<<endl;
}

