class Solution {
    TreeNode* solve(int mini , int maxi , vector<int> pre , int& i ){
        if(i >= pre.size()){
            return NULL ;
        }
        
        //out of range
        if(pre[i] < mini || pre[i] > maxi){
            return NULL ;
        }
        
        TreeNode* temp = new TreeNode(pre[i++]) ;
        
        temp-> left = solve(mini , temp-> val , pre , i) ;
        temp-> right = solve(temp-> val , maxi , pre ,i) ;
        
        return temp ;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini = INT_MIN ;
        int maxi = INT_MAX ;
        
        int i = 0 ;
        return solve(mini , maxi , preorder , i) ;
    }
};