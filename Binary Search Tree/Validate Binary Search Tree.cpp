//Range concept we check range for every node in the tree 


class Solution {
private:
    bool isBinarySearchTree(TreeNode* root , long long int min , long long int max){
        //base case
        if(root == NULL){
            return true ;
        }
        
        //first node will check and remaining will check by recursivly 
        if(root-> val > min && root-> val < max){
            bool left = isBinarySearchTree(root-> left , min , root-> val) ;
            bool right = isBinarySearchTree(root-> right , root-> val , max) ;
            
            return ( left && right ) ;
            
        }else{
            return false ;
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        //test case requirement 
        long long int min = LLONG_MIN;
        long long int max = LLONG_MAX;
        return isBinarySearchTree(root , min , max) ;
        
    }
};