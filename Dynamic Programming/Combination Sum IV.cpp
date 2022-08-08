//recursive solution
int solve(vector<int> &num, int tar){
    //base case
    if(tar == 0){
        return 1 ;
    }
    
    if(tar<0){
        return 0 ; 
    }
    
    int ans = 0 ;
    for(int i = 0 ; i < num.size() ; i++){
        int subAns = solve(num , tar - num[i]) ; 
        ans += subAns ;
    }
    
    return ans ;
}

int findWays(vector<int> &num, int tar)
{
    return solve(num , tar) ;
}


//dp solution  Top Down Approach

class Solution {
public:
    int solve(vector<int> &num, int tar , vector<int> &dp){
        //base case
        if(tar == 0){
            return 1 ;
        }

        if(tar<0){
            return 0 ; 
        }

        if(dp[tar] != -1){
            return dp[tar] ;
        }

        int ans = 0 ;
        for(int i = 0 ; i < num.size() ; i++){
            int subAns = solve(num , tar - num[i] , dp) ; 
            ans += subAns ;
        }

        dp[tar] =  ans ;
        return dp[tar] ;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1 , -1) ;
        return solve(nums , target , dp) ;
    }
};


// bottom up approach

int solve(vector<int> &num, int tar){
    vector<int> dp(tar+10) ;
    dp[0] = 1 ;

    if(tar<0){
        return 0 ; 
    }

    
    // 1-tar sathi dp vector fill karaycha so loop
    for(int i = 1 ; i<=tar ; i++){

        int ans = 0 ;
        //nums array loop to calculate
        for(int j = 0 ; j < num.size() ; j++){
            if(i - num[j] >= 0){
                int subAns = dp[i - num[j]] ;
                ans += subAns ;
            }
        }
        
        dp[i] = ans ;
    }
      
    return dp[tar] ;
}

int findWays(vector<int> &num, int tar)
{
    return solve(num , tar ) ;
}


//Space optimization


