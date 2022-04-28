class Solution {
private:
    void getmapping( vector<int> inorder , int n , map<int,int> &indexToelelement){
        for(int i = 0 ; i<n ; i++){
            indexToelelement[inorder[i]] = i ;
        }
        
    }
    TreeNode* solve(vector<int> postorder , vector<int> inorder , int &index , int instart , int inend , int n , map<int,int> &indexToelelement){
        //base case
        if(index < 0 || instart >  inend){
            return NULL ;
        }
        
        //get element
        int element = postorder[index--] ;
        TreeNode* root = new TreeNode(element) ;
        int position = indexToelelement[element];
        
        //recursive calls
        
        root-> right = solve(postorder,inorder,index,position+1,inend,n , indexToelelement) ;
        root-> left = solve(postorder,inorder,index,instart,position-1,n, indexToelelement) ;
        
        return root ;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size() ;
        int index =  n-1;
        
        map<int,int> indexToelement ;
        
        getmapping(inorder,n ,indexToelement) ;
        TreeNode* root = solve(postorder , inorder , index , 0 , n-1 , n , indexToelement) ;
        return root ;
    }
};