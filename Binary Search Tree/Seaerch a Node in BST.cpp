//recursive way

bool search(Node* root, int x) {
    
    //base case
    if(root == NULL){
        return false ;
    }
    
    if(root-> data < x){
        search(root-> right , x) ;
    }else if(root-> data > x){
        search(root-> left , x) ;
    }else {
        return true ;
    }
}


//iterative way
bool search(Node* root, int x) {

    while(root != NULL){
            if(root-> data == x){
                return true ;
            }else if(root-> data > x){
                root = root-> left ;
            }else{
                root = root-> right ;
            }
        }
        
        return false ;
}