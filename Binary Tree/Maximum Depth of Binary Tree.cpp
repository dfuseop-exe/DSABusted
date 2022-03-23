class Solution {
public:
    int maxDepth(TreeNode* root) {
        //base case
        if(root == NULL){
            return 0 ;
        }
        
        int leftHeight = maxDepth(root-> left) ; 
        int rightHeight = maxDepth(root-> right) ;
        
        int ans = max(leftHeight,rightHeight) + 1 ;
        
        return ans ;

    }
};