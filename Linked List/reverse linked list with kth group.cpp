Node* kReverse(Node* head, int k) {
    //base case
    if(head == NULL){
        return head;
    }
    

    //reverse first k node
   Node* curr = head ;
   Node* prev = NULL ;
   Node* next = NULL ;
   int count = 0 ;
 
    while(curr != NULL && count < k){
        //reverse 2 node logic
        
        next = curr-> next ;
        curr-> next = prev ;
        prev = curr ;
        curr = next ;
        count++;
    }
    
    // steps recursive call
    //check aage ka node null to nhi
    // if(next != NULL){
    //     head-> next = kReverse(next,k);
    // }
    //valid
    head-> next = kReverse(next,k);
    
    return prev ;
}