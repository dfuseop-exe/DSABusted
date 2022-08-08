class Solution {
  public:
    bool isCBT(struct Node* root , int cnt , int i){
        //base case
        if(root == NULL){
            return true ;
        }
        
        //= coz it is zero based indexing 0-4 is valid 5 is invalid
        if(i >= cnt){
            //as it is out of range
            return false ;
        }else{
            //if current node is in range 
            //check for child
            bool left = isCBT(root-> left , cnt , (2*i)+ 1) ;
            bool right = isCBT(root-> right , cnt , (2*i)+ 2) ;
            
            return (left && right) ;
        }
    }
    
    bool isHeapOrder(struct Node* root){
        //base case
        if(root == NULL){
            return true ;
        }    
        
        //leaf node are always heap order
        if(root-> left == NULL && root-> right == NULL) {
            return true ;
        }
        
        //for only left node as only right cant axist as it is CBT 
        if(root-> right == NULL){
            return (root-> data > root-> left-> data ) ;
        }else{
            
            return (root-> left-> data < root-> data) && (root-> right-> data < root-> data)
            && isHeapOrder(root-> left) && isHeapOrder(root-> right) ;
        }
    }
    
    int countNodes(struct Node* root){
        //base case
        if(root == NULL){
            return 0 ;
        }
        
        int ans = 1 + countNodes(root-> left) + countNodes(root-> right) ;
        return ans ;
    }
    bool isHeap(struct Node* tree) {
        //2 condition should satisfy  
        //should CBT
        //should in max heap order
        

        //0 based indexing
        int i = 0 ;
        
        //required for CBT check (range)
        int cnt = countNodes(tree) ;
        
        //check both condition
        if(isCBT(tree , cnt , i) && isHeapOrder(tree)){
            return true ;
        }else{
            return false ;
        }
        
    }
};