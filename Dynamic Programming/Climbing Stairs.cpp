class Solution {
public:
    int check(int n , vector<int> &dp){
        if(n <= 2)
            return n;
        
        if(dp[n] != -999){
            return dp[n] ;
        }
        
        //recursive relation
        dp[n] = check(n-1 , dp) + check(n-2 ,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1 , -999) ;
        return check(n , dp) ;
    }
};


//bottom up approach

class Solution{
	public:
		int nthPoint(int n){
		   const unsigned int M = 1000000007;
		   vector<int> dp(n+1) ;
		   
		  
		   dp[1] = 1 ;
		   dp[2] = 2 ;
		   
		   for(int i = 3 ; i <= n ; i++){
		       dp[i] = (dp[i-1] % M) + (dp[i-2] % M) ;
		       
		   }

		   return (dp[n]% M)  ;
		}
};

