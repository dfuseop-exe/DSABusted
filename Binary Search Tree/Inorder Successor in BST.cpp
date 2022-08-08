class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {   
        Node* succ = NULL ;
        
        //find that node
        Node* temp = root ;
        
        while(temp-> data != x-> data){
            if(temp-> data > x-> data){
                succ = temp ;
                temp = temp-> left ;
            }else{
                temp = temp-> right ;
            }
        }
        
        //till now we find that node
        
        //succ 
        //right subtree ka minimum
        
        Node* rightTree = temp-> right ;
        
        while(rightTree != NULL){
            succ = rightTree ;
            rightTree = rightTree-> left ;
        }
        
        return succ ;
        
    }
};