class Solution {
public:
    int ans ;
    void solve(TreeNode* root , int k , int& i){
        //base case
        if(root == NULL){
            return ;
        }
        
        //L
        solve(root-> left , k , i) ;
        
        //N
        if(k == i){
            ans = root-> val ;
            i++ ;
            return ;
        }else{
            i++ ;
        }
        
        //R
        solve(root-> right , k , i) ;
    }

    int kthSmallest(TreeNode* root, int k) {
        //maintain the count for kth smallest node 
        int i = 1 ;
        ans = -1 ;
        solve(root , k , i) ;
        return ans ;
    }
};