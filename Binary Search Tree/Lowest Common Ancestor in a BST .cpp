//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   //base case
   if(root == NULL){
       return NULL ;
   }
   
   //same part me honge right
   if(root-> data < n1 && root-> data < n2){
       return LCA(root-> right , n1 , n2) ;
   }

   //same part me honge left
   if(root-> data > n1 && root-> data > n2){
       return LCA(root-> left , n1 , n2) ;
   }
   
   //ya to different parts me honge LCA is root 
   return root ;
}

