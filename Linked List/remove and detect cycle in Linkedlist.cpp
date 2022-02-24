//detection and also return intersection point using floyd cycle detection algo
Node* FCD(Node* head){
    if(head == NULL){
        return NULL ;
    }
    
    Node* slow = head ;
    Node* fast = head ;
    
    while(slow != NULL && fast != NULL){
        fast = fast-> next ;
        
        if(fast != NULL){
            fast = fast-> next ;
        }
        
        slow = slow-> next ;
        
        if(slow == fast){
            return slow ;
        }
    }
    return NULL ;
}

Node* getStartNode(Node* head){
    if(head == NULL)
        return NULL ;
    
    Node* intersectionPoint = FCD(head);
    
    if(intersectionPoint == NULL){
        return NULL ;
    }
    
    Node* slow = head ;
    
    while(slow != intersectionPoint){
        slow = slow->next ;
        intersectionPoint = intersectionPoint-> next ;
    }
    return slow ;
}

Node *removeLoop(Node *head)
{
    Node* start = getStartNode(head);
    
    if(start == NULL){
        return head ;
    }
    
    Node* temp = start ;
    
    while(temp-> next != start){
        temp = temp-> next ;
    }
    
    temp-> next = NULL ;
    
    return head ;
}