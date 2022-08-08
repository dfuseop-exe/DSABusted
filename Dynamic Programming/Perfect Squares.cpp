//Recursive solution 
class Solution {
public:
    int solve(int n ,vector<int> &dp){
            //base case
	    if(n == 0){
	        return 0 ;
	    }
	    
	    if(dp[n] != -1){
	        return dp[n] ;
	    }
	    
	    int count = n ;
	    for(int i = 1 ; i*i <= n ; i++){
	        int subAns = solve(n-(i*i) , dp) ;
	        count = min(subAns , count) ;
	        count++ ;
	    }
	    
	    dp[n] = count ;
	    return dp[n] ;
    }
    int numSquares(int n) {
        vector<int> dp(n+1 , -1) ;
        return solve(n , dp) ;
    }
};


//top down approach dp

class Solution {
public:
    int solve(int n ,vector<int> &dp){
        //base case
        if(n == 0){
            return 0 ;
        }
        
        if(dp[n] != -1){
            return dp[n] ;
        }
        
        //initially
        //minimum ans cab be formed atleast by 1^2 so that makes n ele of combination square
        int ans = n ;
        //check with different options 
        for(int i = 1 ; i*i <= n ; i++){
            int subAns = solve(n - (i*i) , dp) ;
            subAns = subAns + 1 ;
            ans = min(ans , subAns) ;
        }
        
        dp[n] = ans ;
        return dp[n] ;
    }
    int numSquares(int n) {
        vector<int> dp(n+1 , -1) ;
        return solve(n , dp) ;
    }
};


//bottom up approach DP 
class Solution {
public:
   int solveTab(int n){
        vector<int> dp(n+1 , 0) ;
        dp[0] = 0 ;
        
        for(int i = 1 ; i <= n ; i++){
            int ans = n ;
            //check with different options 
            for(int j = 1 ; j*j <= n ; j++){
                if(i - (j*j) >= 0){
                    int subAns = dp[i - (j*j)];
                    subAns = subAns + 1 ;
                    ans = min(ans , subAns) ;
                }
            }
            
            dp[i] = ans ;
        }
        
        return dp[n] ;
        
    }
    
    int numSquares(int n) {
       
        return solveTab(n) ;
    }
}