Node* reverse(Node* head){
    //base case 
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* chotahead  = reverse(head->next);

    head-> next-> next = head ;
    head-> next = NULL ;
    return chotahead ;
}

/*void reverse(Node* &head , Node* Curr, Node* Prev){
    ///base case
    if(Curr == NULL){
        head = Prev ;
        return ;
    }
    
    Node* Forward = Curr-> next ;
    reverse(head,Forward,Curr);
    Curr-> next = Prev ;
}
*/
Node* reverseLinkedList(Node *head)
{
    
    return reverse(head);
    /*Node* Prev = NULL ;
    Node* Curr = head ;
    
    reverse(head,Curr,Prev);
    return head;
    
    Node* Forward = NULL ;
    Node* Prev = NULL ;
    Node* Curr = head ;
    
    while(Curr != NULL){
        Forward = Curr-> next ;
        Curr-> next = Prev ;
        Prev = Curr ;
        Curr = Forward ;
    }
    return Prev ; */
    
}
