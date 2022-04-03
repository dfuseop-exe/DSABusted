class Solution {
bool check(vector<int> t1 , vector<int>t2){
    if(t1.size() != t2.size()){
        return false ;
    }
    
    bool ans = true ;
    
    for(int i = 0 ; i< t1.size() ; i++){
        if(t1[i] != t2[i]){
            ans = false ;
        }
    }
    
    return ans ;
}
void leafNode(TreeNode* root , vector<int> &ans ){
   
    //base case
    if(root == NULL){
        return ;
    }
    
    if((root-> left == NULL) && (root-> right == NULL)){
        ans.push_back(root-> val) ;
    }
    
    leafNode(root-> left , ans) ;
    leafNode(root-> right ,  ans) ;
}
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> t1 ;
        vector<int> t2 ;
        
        leafNode(root1 , t1) ;
        leafNode(root2 , t2) ;
        
        return check(t1 , t2) ;
    }
};