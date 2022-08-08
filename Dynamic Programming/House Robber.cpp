class Solution {
public:
    int solve(vector<int> &nums , int n , vector<int> &dp){
        Maximize The Cut Segment
        
        //range break condition
        if(0 > n){
            return 0 ;
        }
        
        if(dp[n] != -1){
            return dp[n] ;
        }
        
        int include = solve(nums , n-2 , dp) + nums[n] ;
        int exclude = solve(nums , n-1 , dp) + 0 ;
        
        dp[n] = max(include ,exclude) ;
        return dp[n] ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> dp(n+1 , -1) ;
        return solve(nums, n-1 , dp) ;
    }
};



//right to left solution

class Solution {
public:
    int solve(vector<int>& nums ,int i , int n , vector<int> &dp){
        
        if(i > n){
            return 0 ;
        }
        
        if(dp[i] != -1){
            return dp[i] ;
        }
        
        int inc = solve(nums , i+2 , n , dp) + nums[i] ;
        int exc = solve(nums , i+1 , n , dp) ;
        
        dp[i] = max(inc , exc) ;
        return dp[i] ;
        
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0] ;
        }
        
        int n = nums.size() ;
        
        vector<int> dp(n+1 , -1) ;
        
        return solve(nums , 0 , n-1 , dp) ;
    }
};