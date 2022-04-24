class Solution {
private:
    pair<bool,int> isBalancedFast(TreeNode* root) {
        if(root == NULL){
            pair<bool,int> ans = make_pair(true,0) ;
            return ans ;
        }
        
        //go to last to hit base case it will give some values
        pair<bool,int> leftAns = isBalancedFast(root-> left) ;
        pair<bool,int> rightAns = isBalancedFast(root-> right) ;
        
        //get base case reply is Balanced 
        bool isLeft = leftAns.first ;
        bool isright = rightAns.first ;
        
        //we check for current node is Balanced //or Handler
        bool isDiff = abs(leftAns.second - rightAns.second) <= 1 ;

        //ans pair
        pair<bool,int> ans ;
        
        //store height which will required for handler
        ans.second = max(leftAns.second , rightAns.second) + 1 ;
        
        if(isLeft && isright && isDiff){
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