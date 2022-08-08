class Solution {
    void solve(vector<int> &in , TreeNode *root ){
        //base case 
        if(root == NULL){
            return;
        }
        
        solve(in , root-> left) ;
        in.push_back(root-> val) ;
        solve(in , root-> right);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> in ;
        solve(in , root) ;
        
        int i = 0 ;
        int j = in.size()-1 ;
        
        while(i<j){
            if(in[i] + in[j] == k){
                return true ;
            }else if(in[i] + in[j] > k){
                j-- ;
            }else {
                i++ ;
            }
        }
        
        return false ;
    }
};