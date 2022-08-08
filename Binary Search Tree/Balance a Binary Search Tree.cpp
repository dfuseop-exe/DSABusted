class Solution {
    TreeNode* inorderToBst(int s , int e , vector<int> inorder ){
        //base case
        if(s>e){
            return NULL ;
        }
        
        int mid = (s+e) / 2 ;
        
        TreeNode* root = new TreeNode(inorder[mid]) ;
        root-> left = inorderToBst(s , mid-1 , inorder) ;
        root-> right = inorderToBst(mid+1 , e , inorder) ;

        return root ;
    }
    
    void inorderTraversal(TreeNode* root , vector<int>& inorder){
        if(root == NULL){
            return ;
        }
        
        inorderTraversal(root-> left , inorder) ;
        inorder.push_back(root-> val) ;
        inorderTraversal(root-> right , inorder) ;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        //step : 1
        //create inorder traversal nd store in vector 
        
        vector<int> inorder ;
        inorderTraversal(root , inorder) ;
        
        //step 2 :
        //now find mid nd process array to bst logic
        
        return inorderToBst(0 , inorder.size()-1 , inorder) ;
        
    }
};