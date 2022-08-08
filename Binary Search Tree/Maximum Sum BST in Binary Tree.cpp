class Info{
    public:
        int maxi ;
        int mini ;
        bool isBST ;
         int sum ;
};
class Solution {
public:
    
    Info solve(TreeNode* root , int &ans){
        //base case
        if(root == NULL){
            return {INT_MIN ,INT_MAX , true , 0} ;
        }
        
        Info left = solve(root-> left , ans) ;
        Info right = solve(root-> right , ans) ;
        
        Info CurrNode ;
        
        CurrNode.maxi = max(root-> val , right.maxi) ;
        CurrNode.sum =  left.sum + right.sum + root-> val ;
        CurrNode.mini = min(root-> val , left.mini) ;
        
        if(right.isBST && left.isBST && (root-> val < right.mini && root-> val > left.maxi)){
            CurrNode.isBST = true ;
        }else{
            CurrNode.isBST = false ;
        }
        
        if(CurrNode.isBST){
            ans = max(ans , CurrNode.sum);
        }
        
        return CurrNode ;
    }
    
    int maxSumBST(TreeNode* root) {
        int Maxsum = 0 ;
    	Info temp = solve(root , Maxsum) ;
        return Maxsum ;
    }
};