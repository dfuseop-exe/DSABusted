//top down approach

#include<limits.h>
int solve(int x ,int y , int z , int n , vector<int> &dp){
    if(n == 0){
        return 0 ;
    }
    
    if(n < 0){
        return INT_MIN ;
    }
    
    if(dp[n] != -1){
        return dp[n] ;
    }
    
  
    int a = solve(x ,y , z , n - x , dp) + 1 ;
    int b = solve(x ,y , z , n - y , dp) + 1 ;
    int c = solve(x ,y , z , n - z , dp) + 1 ;

    int ans = max(a , max(b , c)) ;

    
    dp[n] = ans ;
    return dp[n] ;
}

int cutSegments(int n, int x, int y, int z) {
    
    vector<int> dp(n+1 , -1) ;
    int ans = solve(x ,y ,z , n , dp) ;
    if(ans > 0){
        return ans ;
    }
    
    return 0 ;
}


//bottom up approach

