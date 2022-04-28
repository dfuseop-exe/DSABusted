class Solution{
    private:
    
    int getPostion(int inorder[] , int inorderstart , int inorderend ,int ele , int n){
        //get position
        for(int i = 0 ; i<n ; i++ ){
            if(inorder[i] == ele){
                return i ;
            }
        }
        
        return -1 ;
    }
    
    Node* solve(int inorder[] , int preorder[] , int &index , int inorderstart , int inorderend , int n){
        //base case
        if(index >= n || inorderstart > inorderend){
            return NULL ;
        }
        
        //get root element
        int element = preorder[index++] ;
        Node* root = new Node(element) ;
        
        //find position in of root in inorder
        int position = getPostion(inorder , inorderstart , inorderend , element , n ) ;
        
        
        //recursive calls
        root-> left = solve(inorder , preorder , index , inorderstart , position-1 , n) ;
        root-> right = solve(inorder , preorder , index , position+1 , inorderend , n) ;
        
        return root ;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        //for preorder first element access
        int index = 0 ;
        Node* ans = solve(in , pre , index , 0 , n-1 , n) ;
        return ans ;
        
    }
};


///using map

class Solution {
private:
    void getmapping( vector<int> inorder , int n , map<int,int> &indexToelelement){
        for(int i = 0 ; i<n ; i++){
            indexToelelement[inorder[i]] = i ;
        }
        
    }
    TreeNode* solve(vector<int> preorder , vector<int> inorder , int &index , int instart , int inend , int n , map<int,int> &indexToelelement){
        //base case
        if(index >= n || instart >  inend){
            return NULL ;
        }
        
        //get element
        int element = preorder[index++] ;
        TreeNode* root = new TreeNode(element) ;
        int position = indexToelelement[element];
        
        //recursive calls
        root-> left = solve(preorder,inorder,index,instart,position-1,n, indexToelelement) ;
        root-> right = solve(preorder,inorder,index,position+1,inend,n , indexToelelement) ;
        
        return root ;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0 ;
        int n = inorder.size() ;
        
        map<int,int> indexToelement ;
        
        getmapping(inorder,n ,indexToelement) ;
        TreeNode* root = solve(preorder , inorder , index , 0 , n-1 , n , indexToelement) ;
        return root ;
    }
};