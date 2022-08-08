class Solution
{
    public:
    int ans = 0;
    
    void solve(Node* root , int&  i , int k){
        //base case
        if(root == NULL){
            return ;
        }
        
        solve(root-> right , i , k) ;
        
        if(i == k){
            ans = root-> data ;
            i++ ;
            return ;
        }else{
            i++ ;
        }
        
        solve(root-> left , i , k) ;
    }
    
    int kthLargest(Node *root, int K)
    {
        //BST's inorder is sorted order but if we store it takes o(n) space 
        //so take counter and traverse inorderly nd count increment so when k becomes = count 
        //that number is kth smallest or for largest just change the L nd R position 
        
        ans = -1 ;
        int i = 1 ;
        solve(root , i , K) ;
        return ans ;
    }
};