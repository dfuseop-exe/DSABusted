class Solution {
private:
    pair<bool,int> isBalancedFast(TreeNode* root) {
        //base case
        if(root == NULL){
                        //      isBalanced , height of null is 0
            pair<bool,int> p = make_pair(true,0) ;
            return p ;
        }
        
        pair<bool,int> left = isBalancedFast(root-> left) ;
        pair<bool,int> right = isBalancedFast(root-> right) ;
        
        
        bool leftAns = left.first ;
        bool rightAns = right.first ;
        
        bool diff = abs(left.second - right.second) <= 1 ;
        
        pair<bool,int> ans ;
        //for storing the height of current node
        ans.second = max(left.second , right.second) + 1 ;
        
        if(leftAns && rightAns && diff){
            ans.first = true ;
            return ans ;
        }else{
            ans.first = false ;
            return ans ;
        }
    }
public:
    bool isBalanced(TreeNode* root) {
        return isBalancedFast(root).first ;
    }
};