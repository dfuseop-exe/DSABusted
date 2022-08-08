Node* inpre(Node* root)
{
    while(root-> right){
        root = root-> right ;
    }
    
    return root ; 
}


Node* insuc(Node* root){
    while(root-> left){
        root = root-> left ;
    }
    
    return root ;

}


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root == NULL){
        return  ;
    }
    
    if(root-> key == key){
        if(root-> left){
            pre = inpre(root->left) ;
        }
        if(root-> right){
            suc = insuc(root->right) ;
        }
        return  ;
    }
    

    //for leaf node case or absulate case
    if(key > root-> key){
        pre = root ;
        findPreSuc(root->right , pre , suc ,key) ;
    }else if(key < root-> key){
        suc = root ;
        findPreSuc(root-> left , pre , suc , key) ;
    }
}