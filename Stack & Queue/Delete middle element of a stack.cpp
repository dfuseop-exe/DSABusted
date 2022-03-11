class Solution
{
    private :
    void solve(stack<int>&s, int size , int count){
        //base case
        if(count == size/2){
            s.pop();
            return ;
        }
        
        int num = s.top();
        s.pop() ;
        
        solve(s,size,count+1);
        
        s.push(num);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int count = 0 ;
        solve(s,sizeOfStack,count) ;
    }
};