//approach 1

int getLength(Node* head){
    int len = 0; 
    while(head != NULL){
        len++;
        head = head-> next;
    }
    return len ;
}
Node *findMiddle(Node *head) {
    int len = getLength(head);
    int mid = (len/2);
    
    Node* temp = head ;
    int cnt = 0 ;
    while(cnt < mid){
        temp = temp-> next ;
        cnt++;
    }
    
    return temp;
}

//optimised approach

    
Node* getmiddle(Node* head){
    
    //check if 0 or 1 node is present then it is middle
    if(head == NULL || head-> next == NULL){
        return head ;
    }

    Node* slow = head; 
    Node* fast = head-> next;
    
    while(fast != NULL){
        fast = fast-> next ;
        
        //check next null to nhi hai ?
        if(fast != NULL){
            fast = fast-> next ;
        }
        
        slow = slow-> next ;
    }
    
    return slow ;
}