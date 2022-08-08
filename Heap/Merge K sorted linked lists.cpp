class compare{
    public :
    bool operator()(Node* a , Node* b){
        return a-> data > b-> data ;
    }
};

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
        //min heap creation
        priority_queue<Node * , vector<Node *> , compare > minheap ;
    
        //step 1 - insert first item if all k LL in heap
        for(int i = 0 ; i < K ; i++){
           if(arr[i] != NULL){
               //as it is LL so arr[i] = head
                minheap.push(arr[i]) ; 
           }
        }        
        
        //step 2 - pop top smallest ele and create new LL
        Node* head = NULL ;
        Node* tail = NULL ;
        
        while(minheap.size() > 0){
            //get top of minheap that is smallest ele node
            Node* top = minheap.top() ;                 
            
            //pop top ele
            minheap.pop() ;
            
            if(top-> next != NULL){
                minheap.push(top-> next) ;
            }
            
            //push it in the new LL
            
            //if it is first ele to be push in LL
            if(head == NULL){
                head = top ;
                tail = top ;
            }else{
                //already nodes are present in ans LL
                tail-> next = top ;
                tail = top ;
            }
            
        }
        
        return head ;
    }
};
