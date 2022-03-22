class Solution {
private:
    void postorder(TreeNode* root , vector<int>& ans){

        //base condition
        if(root == NULL){
            return ;
        }

        
        postorder(root-> left , ans) ;
        postorder(root-> right , ans) ;
        ans.push_back(root-> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans ;
        postorder(root , ans) ;
        return ans ;
    }
};