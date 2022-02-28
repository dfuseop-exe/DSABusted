class Solution {
private:
    
    void insertAtTail(Node* &head , Node* &tail , int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = newNode ;
            tail = newNode ;
            return ;
        }else{
            tail-> next = newNode;
            tail = newNode ;
        }
    }
    
public:
    Node* copyRandomList(Node* head) {
        
    //step - 1 clone a LL
        
        Node* cloneHead = NULL ;
        Node* cloneTail = NULL ;
        
        //for copy 
        Node* temp = head ;
        
        while(temp != NULL){
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp = temp-> next ;
        }
    
    //step - 2 create mapping
    
        unordered_map<Node*,Node*> mapping ;
        
        //pointer to start of both LL
        Node* originalNode = head ;
        Node* cloneNode = cloneHead ;
        
        //both are of same length so take any as itr
        while(originalNode != NULL){
            //mapping to original to clone Node
            mapping[originalNode] = cloneNode ;
            
            //increment pointers
            originalNode = originalNode-> next ;
            cloneNode = cloneNode-> next ;
        }
        
    //step - 3 copy random pointer
        
        //pointer to start of both LL
        originalNode = head ;
        cloneNode = cloneHead ;
        
        //both are of same length so take any as itr
        while(originalNode != NULL){
            
            //copy random pointer
            cloneNode-> random = mapping[originalNode-> random] ;
            
            //increment pointers
            originalNode = originalNode-> next ;
            cloneNode = cloneNode-> next ;
        }
        
        //cloneHead pointer
        return cloneHead ;
    }
};