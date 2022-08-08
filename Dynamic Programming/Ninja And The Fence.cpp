//recursive solution

#define MOD 1000000007 
#include<vector>

int solve(int n , int k){
    if(n == 1){
        return k ;
    }
    
    if(n == 2){
        return k + (k * (k-1)) ;
    }
    
    int ans = ( solve(n-2 , k)%MOD * (k-1)%MOD )%MOD + ( solve(n-1 , k)%MOD * (k-1)%MOD )%MOD ;
}

int numberOfWays(int n, int k) {
    return solve(n , k)%MOD;
}


//top dowm approach dp

#define MOD 1000000007 
#include<vector>

long long int solve(int n , int k , vector<long long int> &dp){
    if(n == 1){
        return k ;
    }
    
    if(n == 2){
        //same color sathi  k + diff color combination  is (k * (k-1)) combination
        return k + (k * (k-1)) ;
    }
    
    if(dp[n] != -1){
        return dp[n] ;
    }
    
    dp[n] = ( solve(n-2 , k , dp)%MOD * (k-1)%MOD )%MOD + ( solve(n-1 , k ,dp)%MOD * (k-1)%MOD )%MOD ;
    return dp[n] ;
}

int numberOfWays(int n, int k) {
    vector<long long int> dp(n+1 , -1) ;
    return solve(n , k , dp)%MOD;
}


//bottom up approach


#define MOD 1000000007 
#include<vector>

long long int solve(int n , int k ){
    vector<long long int> dp(n+1 , -1) ;
    dp[1] = k ;
    dp[2] = k + (k * (k-1)) ;
    
    for(int i = 3 ; i <= n ; i++){
        dp[i] = ( dp[i-2] %MOD * (k-1)%MOD )%MOD + ( dp[i-1] %MOD * (k-1)%MOD )%MOD ;
    }
    
    return dp[n] ;
}

int numberOfWays(int n, int k) {
    return solve(n , k )%MOD;
}

//space optimised


#define MOD 1000000007 
#include<vector>

long long int solve(int n , int k ){
    
    long long int prev2 = k ;
    long long int prev1 = k + (k * (k-1)) ;
    
    for(int i = 3 ; i <= n ; i++){
        long long int curr = (( (prev2 % MOD) * (k-1)%MOD )%MOD + ( (prev1 %MOD) * (k-1)%MOD )%MOD) %MOD;
        prev2 = prev1 ;
        prev1 = curr ;
    }
    
    return prev1 ;
    
}

int numberOfWays(int n, int k) {
    return solve(n , k )%MOD;
}



