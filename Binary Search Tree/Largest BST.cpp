class Info{
    public:
        int maxi ;
        int mini ;
        bool isBST ;
         int size ;
};

class Solution{

    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    Info solve(Node* root , int &ans){
        //base case
        if(root == NULL){
            return {INT_MIN ,INT_MAX , true , 0} ;
        }
        
        Info left = solve(root-> left , ans) ;
        Info right = solve(root-> right , ans) ;
        
        Info CurrNode ;
        
        CurrNode.maxi = max(root-> data , right.maxi) ;
        CurrNode.size = left.size + right.size + 1 ;
        CurrNode.mini = min(root-> data , left.mini) ;
        
        if(right.isBST && left.isBST && (root-> data < right.mini && root-> data > left.maxi)){
            CurrNode.isBST = true ;
        }else{
            CurrNode.isBST = false ;
        }
        
        if(CurrNode.isBST){
            ans = max(ans , CurrNode.size);
        }
        
        return CurrNode ;
    }
    
    int largestBst(Node *root)
    {
    	int maxSize = 0 ;
    	Info temp = solve(root , maxSize) ;
        return maxSize ;
        
    }
};