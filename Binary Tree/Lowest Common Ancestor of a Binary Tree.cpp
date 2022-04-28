class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base case
        if(root == NULL){
            return NULL ;
        }
        
        //base case kota hi ek asla tr vr !null value jail
        if(root == p || root == q){
            return root ;
        }
        
        TreeNode* leftAns = lowestCommonAncestor(root-> left , p , q) ;
        TreeNode* rightAns = lowestCommonAncestor(root-> right , p , q) ;
        
        
        //all cases
        if(leftAns != NULL && rightAns != NULL){
            return root ;
        }else if(leftAns == NULL && rightAns != NULL){
            return rightAns ;
        }else if(leftAns != NULL && rightAns == NULL){
            return leftAns ;
        }else{
            return NULL ;
        }
    }
};