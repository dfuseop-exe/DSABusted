class Solution {
public:
    int minDepth(TreeNode* root) {
        //base case
        if(root == NULL){
            return 0 ;
        }
        
        int leftHeight = minDepth(root-> left) ;                               
        int rightHeight = minDepth(root-> right) ;
        

        //if(one sided tree then left or right height can be 0 so it is not valid ans thats y we return rightheight + 1 for root node)
        if(leftHeight==0)
            return rightHeight+1;
        if(rightHeight==0)
            return leftHeight+1;
        
        int ans = min(leftHeight,rightHeight) + 1 ;
        
        return ans ;
    }
};