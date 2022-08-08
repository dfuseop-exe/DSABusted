//normal recursion solution

class Solution {
public:
    int solve(vector<int>& coins, int amount){
        //base case
        if(amount == 0){
            return 0;
        }
        
        int mini = INT_MAX ;
        
        //we have coins.size() number of choice of coins so we try with all coins to create min 
        for(int i = 0 ; i< coins.size() ; i++){
            //make sure that by substraction of coins[i] th coin from amount the amount is not getting smaller than 0 
            //if then it means not possible with this coin to make amount
            if(amount - coins[i] >= 0){
                int subAns = solve(coins , amount - coins[i]) ;
                //here it may give INT_MAX means their is not possible way to make amount with that coins
                if(subAns != INT_MAX){
                    mini = min(mini , subAns + 1) ;
                }
            }
        }
        
        //it may contain INT_MAX means we are not able to make Amount using Coins
        return mini ;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins , amount) ;
        if(ans == INT_MAX){
            return -1 ; //not possible
        }
        
        return ans ;
    }
};


//DP -  Top Down Approach

class Solution {
public:
    int solve(vector<int>& coins, int amount , vector<int> &dp){
        //base case
        if(amount == 0){
            return 0;
        }
        
        if(dp[amount] != -1){
            return dp[amount] ;
        }
        
        int mini = INT_MAX ;
        
        //we have coins.size() number of choice of coins so we try with all coins to create min 
        for(int i = 0 ; i< coins.size() ; i++){
            //make sure that by substraction of coins[i] th coin from amount the amount is not getting smaller than 0 
            //if then it means not possible with this coin to make amount
            if(amount - coins[i] >= 0){
                int subAns = solve(coins , amount - coins[i] , dp) ;
                //here it may give INT_MAX means their is not possible way to make amount with that coins
                if(subAns != INT_MAX){
                    mini = min(mini , subAns + 1) ;
                }
            }
        }
        
        //step 2 
        dp[amount] = mini ;
        
        //it may contain INT_MAX means we are not able to make Amount using Coins
        return dp[amount] ;
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        //step 1 
        vector<int> dp(amount + 1 , -1); //amount + 1 because we use dp[0] to dp[amount] 
        int ans = solve(coins , amount , dp) ;
        if(ans == INT_MAX){
            return -1 ; //not possible
        }
        
        return ans ;
    }
};