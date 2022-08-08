void solve(vector<int> &in , TreeNode<int>* root ){
        //base case 
        if(root == NULL){
            return;
        }
        
        solve(in , root-> left) ;
        in.push_back(root-> data) ;
        solve(in , root-> right);
    }
TreeNode<int>* flatten(TreeNode<int>* root)
{
    //stote inorder
    vector<int> in ;
    solve(in , root) ;
    
    int n = in.size() ;
    
    //create start node of list 
    TreeNode<int>* newRoot = new TreeNode<int>(in[0]) ;
    
    TreeNode<int>* curr = newRoot ;
    
    for(int i = 1 ; i < n ; i++){
        TreeNode<int>* temp = new TreeNode<int>(in[i]) ;
        
        //2nd step
        curr-> left = NULL ;
        curr-> right = temp ;
        curr = temp ;
        
    }
    
    //3rd step 
    curr-> left = NULL ;
    curr-> right = NULL ;
    
    return newRoot ;
}
