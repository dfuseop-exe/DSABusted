class Solution {
private:
    void traverseLeft(Node* root , vector<int> &ans){
        if(root == NULL){
            return ;
        }
        
        //ignore leaf
        if(root-> left == NULL && root-> right == NULL){
            return ;
        }
        
        //print / store
        ans.push_back(root-> data) ;
        
        if(root-> left){
            traverseLeft(root-> left , ans) ;
        }else{
            traverseLeft(root-> right , ans) ;
        }
    }
    
    void traverseLeaf(Node* root , vector<int> &ans){
        if(root == NULL){
            return ;
        }

        //LNR inorder traversal

        traverseLeaf(root-> left , ans) ;
        
        //check for leaf
        if(root-> left == NULL && root-> right == NULL){
            ans.push_back(root-> data) ;
            return ;
        }
        
        traverseLeaf(root-> right ,ans) ;
    }
    
    void traverseRight(Node* root , vector<int> &ans){
        if(root == NULL){
            return ;
        }
        
        //ignore leaf
        if(root-> left == NULL && root-> right == NULL){
            return ;
        }
        
        if(root-> right){
            traverseRight(root-> right , ans) ;
        }else{
            traverseRight(root-> left , ans) ;
        }
        
        //print / store
        ans.push_back(root-> data) ;
    }
    
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans ;
        
        if(root == NULL){
            return ans ;
        }
        
        //store root data
        ans.push_back(root-> data) ;
        
        //traverse to left
        traverseLeft(root-> left , ans) ;
        
        //traverse leaf node
        //leaf in left subtree
        traverseLeaf(root-> left , ans) ;
        
        //leaf in right subtree
        traverseLeaf(root-> right , ans) ;
        
        //traverse right part
        traverseRight(root-> right , ans) ;
        
        return ans ;
    }
};