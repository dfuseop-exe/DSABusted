//recursive solution

#define MOD 1000000007 
long long int solve(int n){
    //base case
    if(n == 1 || n == 0){
        return 0 ;
    }
    
    if(n == 2){
        return 1 ;
    }
    
    //
    return ((n-1) % MOD) * ((solve(n-2)%MOD) + (solve(n-1)%MOD)) % MOD ; 
}

long long int countDerangements(int n) {
    return solve(n) ;
}


//top down approach dp

#define MOD 1000000007 
#include<vector>

long long int solve(int n , vector<int> &dp){
    //base case
    if(n == 1 || n == 0){
        return 0 ;
    }
    
    if(n == 2){
        return 1 ;
    }
    
    if(dp[n] != -1){
        return dp[n] ;
    }
    
    dp[n] = ((n-1) % MOD) * ((solve(n-2 , dp)%MOD) + (solve(n-1 , dp)%MOD)) % MOD ; 
    return dp[n] ;
}

long long int countDerangements(int n) {
    vector<int> dp(n+1 , -1) ;
    return solve(n , dp) ;
}


//Bottom Up approach dp

#define MOD 1000000007 
#define ll long long int 
#include<vector>

long long int solve(int n){
    
    vector<long long int> dp(n+1 , 0) ;

    
    dp[1] = 0 ;
    dp[2] = 1 ;
    
    for(int i = 3 ; i <= n ; i++){
        ll first = dp[i-1] % MOD ;
        ll second = dp[i-2] % MOD ;
        ll sum = (first + second) % MOD ;
        ll ans = ((i-1) * sum) % MOD ;
        dp[i] = ans ;
    }
    
    //dp[n] = ((n-1) % MOD) * ((solve(n-2 , dp)%MOD) + (solve(n-1 , dp)%MOD)) % MOD ; 
    return dp[n] ;
}

long long int countDerangements(int n) {
    return solve(n) ;
}

//space optimised

#define MOD 1000000007 
#define ll long long int 
#include<vector>

long long int solve(int n){

    ll prev2 = 0 ;
    ll prev1 = 1 ;
    
    for(int i = 3 ; i <= n ; i++){
        ll first = prev1 % MOD ;
        ll second = prev2 % MOD ;
        ll sum = (first + second) % MOD ;
        ll ans = ((i-1) * sum) % MOD ;
        ll curr = ans ;
        
        prev2 = prev1 ;
        prev1 = curr ;
    }
    
    //dp[n] = ((n-1) % MOD) * ((solve(n-2 , dp)%MOD) + (solve(n-1 , dp)%MOD)) % MOD ; 
    return prev1 ;
}

long long int countDerangements(int n) {
    return solve(n) ;
}