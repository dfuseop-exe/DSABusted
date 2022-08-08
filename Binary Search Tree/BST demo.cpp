#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
        int data ;
        Node* right ;
        Node* left ;

        Node(int d) {
            this->data = d;
            this-> right = NULL ;
            this-> left = NULL ;
        }
};

Node* insertIntoBst(Node* root , int d){
    //recursive function
    //base case
    if(root == NULL){
        //no tree is exist so first create root node
        root = new Node(d) ;
        return root ;
    }

    if(d > root->data){
        //right part me insert
        root-> right = insertIntoBst(root->right, d) ;
    }else{
        //left part me insert
        root-> left = insertIntoBst(root->left, d) ;
    } 

    return root ; 
}

void takeInput(Node* &root){
    int data ;
    cin>>data;

    while(data != -1){
        root = insertIntoBst(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q ;
    q.push(root);

    //displaying purpose only
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl ;
            if(!q.empty()){
                q.push(NULL) ;
            }
        }else{
            cout<<temp-> data <<" " ;
            if(temp-> left){
                q.push(temp-> left) ;
            }
            if(temp-> right){
                q.push(temp-> right) ;
            }
        }
    }
}

int main(){
    //create root node
    Node* root = NULL ;

    cout<<"Enter data to insert into bst"<<endl;
    takeInput(root) ;

    cout<<"Displaying Tree"<<endl;
    levelOrderTraversal(root) ;

    return 0 ;
}