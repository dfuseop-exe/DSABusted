bool isCircular(Node* head){
   //empty node is true
   if(head == NULL){
       return true ;
   }
    
    Node* temp = head-> next ;
    
    while(head != NULL && temp != head){
        temp = temp -> next ;
    }
    
    if(temp == head){
        return true ;
    }
    return false ;  
}