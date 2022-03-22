/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        //for storing level of tree
        vector<vector<int>> ans; 
        //if condition is true return empty ans
        if(root == NULL) return ans; 
        
        //create a queue and push root node
        queue<TreeNode*> q; 
        q.push(root); 
        
        //now process untill queue become empty
        while(!q.empty()) {
            
            //for loop over level element 
            int size = q.size();
            //storing element of level
            vector<int> level; 
            
            for(int i = 0;i<size;i++) {
                TreeNode *node = q.front(); 
                q.pop(); 
                
                if(node->left != NULL) q.push(node->left); 
                if(node->right != NULL) q.push(node->right); 
                
                //pushing element to level vector
                level.push_back(node->val); 
            }
            //pushing all level to ans vector
            ans.push_back(level); 
        }
        return ans; 
    }
};