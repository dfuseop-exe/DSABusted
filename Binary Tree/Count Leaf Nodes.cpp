void inorder(BinaryTreeNode<int> *root , int &sum){
        
        //base condition
        if(root == NULL){
            return ;
        }

        
        inorder(root-> left , sum) ;
        
        if(root-> left == NULL && root-> right == NULL){
            sum++ ;
        }
        
        inorder(root-> right , sum) ;
    }

int noOfLeafNodes(BinaryTreeNode<int> *root){
   		int sum = 0 ;
        inorder(root , sum) ;
        return sum ;
}