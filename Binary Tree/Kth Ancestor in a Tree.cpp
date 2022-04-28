Node* solve(Node* root , int &k , int node){
    //base case
    if(root == NULL){
        return NULL;
    }
    
    if(root-> data == node){
        return root ;
    }
    
    Node* leftAns = solve(root-> left , k , node) ;
    Node* rightAns = solve(root-> right , k , node) ;
    
    if(leftAns != NULL && rightAns == NULL){
        k-- ;
        if(k == 0){
            return root ;
        }else{
            return leftAns ;
        }
    }else if(leftAns == NULL && rightAns != NULL){
        k-- ;
        if(k == 0){
    
            return root ;
        }else{
            return rightAns ;
        }
    }
    return NULL ;
}

int kthAncestor(Node *root, int k, int node)
{
    Node* ans = solve(root , k , node) ;
    
    //if root-> data == node asl tr k ancenstor tr nhi nighu shakt so ti case sathi second condition 
    if(ans == NULL || ans-> data == node){
        return -1 ;
    }else {
        return ans-> data ;
    }
}