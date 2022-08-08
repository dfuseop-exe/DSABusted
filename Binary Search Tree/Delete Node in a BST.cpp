class Solution {
private:
    bool search(TreeNode* root, int x) {
    
    while(root != NULL){
            if(root-> val == x){
                return true ;
            }else if(root-> val > x){
                root = root-> left ;
            }else{
                root = root-> right ;
            }
        }
        
        return false ;
    }
    
    TreeNode* minValue(TreeNode* root){
        while(root-> left){
            root = root-> left ;
        }
        
        return root ;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //base case
        if(root == NULL){
            return root ;
        }
        
        if(!search(root,key)){
            return root ;
        }else{
            
            if(root-> val == key){
                
                //case 1 - 0 child
                if(root-> left == NULL && root-> right == NULL){
                    delete root ;
                    return NULL ;
                }

                //case 2 - 1 child

                //left
                if(root-> left != NULL && root-> right == NULL){
                    TreeNode* temp = root-> left ;
                    delete root ;
                    return temp ;
                }

                //right
                if(root-> left == NULL && root-> right != NULL){
                    TreeNode* temp = root-> right ;
                    delete root ;
                    return temp ;
                }

                //case 3 - 0 child
                if(root-> left != NULL && root-> right != NULL){
                    //option 1 = take mini value from right
                    //option 2 = take maxi value from left

                    //option 1

                    int mini = minValue(root->right) -> val ;
                    root-> val = mini ;
                    root-> right = deleteNode(root-> right , mini) ;
                    return root ;
                }
                
            }else if(root-> val < key){
                root-> right = deleteNode(root-> right , key) ;
                return root ;
            }else{
                root-> left = deleteNode(root-> left , key) ;
                return root ;
            }
        }
        return root ;
    }
};