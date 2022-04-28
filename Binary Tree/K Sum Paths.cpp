class Solution{
  private:
    void solve(Node* root , int &count , vector<int> path , int k){
        //base case
        if(root == NULL){
            return ;
        }
        
        //add node to the path
        path.push_back(root-> data) ;
        
        solve(root-> left , count , path , k) ;
        solve(root-> right , count , path , k) ;
        
        //check k sum path is exist in current path ?
        int size = path.size() ;
        int sum = 0 ;
        
        for(int i = size-1 ; i >= 0 ; i--){
            sum += path[i] ;
            if(sum == k){
                count++ ;
            }
        }
        
        //when go back to caller node pop current node from path
        path.pop_back() ;
    }
  public:
    int sumK(Node *root,int k)
    {
        //solve using recursion so creating new function
        vector<int> path ;
        int count = 0 ;
        
        solve(root , count , path , k) ;
        return count ;
    }
};