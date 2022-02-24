//Approach 2 - replace data

Node* sortList(Node *head)
{
    //counter
	int zeroCount = 0 ;
    int oneCount = 0 ;
    int twoCount = 0 ;
    
    //iterator
    Node* temp = head ;
    
    while(temp != NULL){
        
        if(temp-> data == 0){
            zeroCount++ ;
        }else if(temp-> data == 1){
            oneCount++ ;
        }else if(temp-> data == 2){
            twoCount++ ;
        }
        
        temp = temp-> next ;
    }
    
    temp = head ;
    
    //inserting data    
    while(temp != NULL){
        
        if(zeroCount != 0){
			temp-> data = 0 ;
            zeroCount-- ;
        }else if(oneCount != 0){
            temp-> data = 1 ;
            oneCount-- ;
        }else if(twoCount != 0){
            temp-> data = 2 ;
            twoCount-- ;
        }
        
        temp = temp-> next ;
    }
    
    return head ;

}



//Approach 2 - replace link 
//create seperate LL for 0 1 2  and merge 

Node* sortList(Node *head)
{
   Node* zeroHead = new Node(-1) ;
   Node* zeroTail = zeroHead ;
   Node* oneHead = new Node(-1) ;
   Node* oneTail = oneHead ;
   Node* twoHead = new Node(-1) ;
   Node* twoTail = twoHead ;

   Node* temp = head ;
   
    
   while(temp != NULL){
       if(temp-> data == 0){
           zeroTail-> next = temp ;
           zeroTail = temp ;
       }else if(temp-> data == 1){
           oneTail-> next = temp ;
           oneTail = temp ;
       }else if(temp-> data = 2){
           twoTail-> next = temp ;
           twoTail = temp ;
       }
       
       temp = temp-> next ;
   }
    
    if(oneHead-> next != NULL){
        zeroTail-> next = oneHead-> next ;
		oneTail-> next = twoHead-> next ;
    }else{
        zeroTail-> next = twoHead-> next ;
    }
    
    twoTail-> next = NULL ;
    
    head = zeroHead-> next ;
    
    delete zeroHead ;
    delete oneHead ;
    delete twoHead ;
    
    return head ;
}
