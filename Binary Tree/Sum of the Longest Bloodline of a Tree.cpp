class Solution
{
private:
    void solve(Node* root , int len , int &maxlen , int sum , int &maxsum){
        //base case
        if(root == NULL){
            //first condition
            if(len > maxlen){
                //len is large so we need to overwrite both values 
                maxlen = len ;
                maxsum = sum ;
            }
            else if(len == maxlen){
                //len is equal so we need to overwrite larges sum among both values
                maxsum = max(sum,maxsum) ;
            }
            
            // we have to go back to caller node 
            return ;
        }
        
        sum = (root-> data) + sum ;
        
        solve(root-> left , len+1 , maxlen , sum , maxsum) ;
        solve(root-> right , len+1 , maxlen , sum , maxsum) ;
    }
public:
    int sumOfLongRootToLeafPath(Node *root)
    {
        int len = 0 ;
        int maxlen = 0 ;
        
        int sum = 0 ;
        int maxsum = INT_MIN ;
        
        solve(root , len , maxlen , sum , maxsum) ;
        
        return maxsum ;
    }
};