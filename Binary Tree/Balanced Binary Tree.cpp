class Solution {
private:
    pair<bool,int> isBalancedFast(TreeNode* root) {
        //base case
        if(root == NULL){
            pair<bool,int> p = make_pair(true,0) ;
            return p ;
        }
        
        pair<bool,int> left = isBalancedFast(root-> left) ;
        pair<bool,int> right = isBalancedFast(root-> right) ;
        
        
        bool leftAns = left.first ;
        bool rightAns = right.first ;
        
        bool diff = abs(left.second - right.second) <= 1 ;
        
        pair<bool,int> ans ;
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