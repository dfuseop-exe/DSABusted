class Solution {
public:
    int countNodes(TreeNode* root){
        //base case
        if(root == NULL){
            return 0 ;
        }
        
        //1 for current node addition in ans
        int ans = 1 + countNodes(root->left) + countNodes(root-> right) ;
        return ans ;
    }
    
    bool isCBT(TreeNode* root , int cnt , int i){
        if(root == NULL){
            return true ;
        }
        
        //out of range
        if(i >= cnt){
            return false ;
        }else{
            bool left = isCBT(root->left , cnt , (2*i) + 1) ;
            bool right = isCBT(root->right , cnt , (2*i) + 2) ;
            return (left && right) ;
        }
    }
    
    bool isCompleteTree(TreeNode* root) {
        int cnt = countNodes(root) ;
        int index = 0 ;
        return isCBT(root , cnt , index) ;
    }
};