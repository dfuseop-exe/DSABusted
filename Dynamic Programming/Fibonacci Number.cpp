class Solution {
public:
    int fibb(int n , vector<int> &dp){
        if(n <= 1)
            return n;
        
        if(dp[n] != -1){
            return dp[n] ;
        }
        
        dp[n] = fibb(n-1 , dp) + fibb(n-2 , dp) ;
            
        return dp[n] ;
    }
    int fib(int n) {
        vector<int> dp(n+1 , -1) ;
        return fibb(n , dp) ;
    }
};


class Solution {
public:
    
    //bottom up approach
    int fib(int n) {
        
        if(n == 0){
            return n ;
        }
        //step -1 create a vector
        vector<int> dp(n+1) ;
        
        //step - 2 check base case
        dp[0] = 0 ;
        dp[1] = 1 ;
        
        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2] ;
        }
        

        return dp[n] ;
    }
};

\\ space optimised

class Solution {
public:
    
    //bottom up approach
    int fib(int n) {
        
        if(n == 1 || n == 0){
            return n ;
        }
        
        int curr ;
        int prev1 = 1 ;
        int prev2 = 0 ;
        
        for(int i = 2 ; i <= n ; i++){
            curr = prev1 + prev2 ;
            
            //shift logic
            prev2 = prev1 ;
            prev1 = curr ;
        }
        
        return curr ;
    }
};

