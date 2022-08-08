//recursive solution

class Solution {
public:
    int solve(vector<int> nums , int n){
        //base case
        if(n < 0){
            return 0 ;
        }
        
        int include = solve(nums , n-2) + nums[n] ;
        int exclude = solve(nums , n-1) + 0 ;
        
        return max(include , exclude) ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> first , second ;
        
        for(int i = 0 ; i < n ; i++){
            if(i != n-1){
                first.push_back(nums[i]) ;
            }
            
            if(i != 0){
                second.push_back(nums[i]) ;
            }
        }
        
        return max(solve(first , n-2),solve(second , n-2)) ;
    }
};


//dp - Top down Approach
class Solution {
public:
    int solve(vector<int> nums , int n , vector<int> &dp){
        //base case
        if(n < 0){
            return 0 ;
        }
        
        if(dp[n] != -1){
            return dp[n] ;
        }
        
        int include = solve(nums , n-2 , dp) + nums[n] ;
        int exclude = solve(nums , n-1 , dp) + 0 ;
        
        dp[n] = max(include , exclude) ;
        return dp[n] ;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size() ;
        
        //single value case
        if(n == 1){
            return nums[0] ;
        }
        
        vector<int> first , second ;

        for(int i = 0 ; i < n ; i++){
            if(i != n-1){
                first.push_back(nums[i]) ;
            }
            
            if(i != 0){
                second.push_back(nums[i]) ;
            }
        }
        
        vector<int> dp(n , -1);
        int f = solve(first , n-2 , dp) ;
            
        fill(dp.begin(), dp.end(), -1);
        int s = solve(second , n-2 , dp) ;
        
        return max(f,s) ;
    }
};


//space optimised - Bottom-up Approach DP

class Solution {
public:
    int solve(vector<int> nums){
        int prev1 = nums[0] ;
        int prev2 = 0 ;

        for(int i = 1 ; i < nums.size() ; i++){
            int include = prev2 + nums[i] ;
            int exclude = prev1 + 0 ;
            int ans = max(include , exclude) ;
            prev2 = prev1 ;
            prev1 = ans ;
        }
 
        return prev1 ; 
    }
    
    int rob(vector<int>& nums) {
        
        int n = nums.size() ;
        
        //single value case
        if(n == 1){
            return nums[0] ;
        }
        
        vector<int> first , second ;

        for(int i = 0 ; i < n ; i++){
            if(i != n-1){
                first.push_back(nums[i]) ;
            }
            
            if(i != 0){
                second.push_back(nums[i]) ;
            }
        }
        

        int f = solve(first) ;
        int s = solve(second ) ;
        
        return max(f,s) ;
    }
};