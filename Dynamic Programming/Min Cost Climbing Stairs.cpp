class Solution {
public:
    /* normal recursion
    int solve(vector<int>& cost , int n){
        //base case 
        if(n == 0){
            return cost[0] ;
        }
        
        if(n == 1){
            return cost[1] ;
        }
        
        return min(solve(cost , n-1) , solve(cost , n-2)) + cost[n];
    } */
    
    /* top down approach
    int solve(vector<int>& cost , int n ,vector<int> &dp ){
        //base case 
        if(n == 0){
            return cost[0] ;
        }
        
        if(n == 1){
            return cost[1] ;
        }
        
        if(dp[n] != -1){
            return dp[n] ;
        }
        
        dp[n] = min(solve(cost , n-1 , dp) , solve(cost , n-2 , dp)) + cost[n];
        return dp[n] ;
    } */
    
    /*int solve(vector<int>& cost , int n , vector<int> &dp ){

        dp[0] = cost[0] ;
        dp[1] = cost[1] ;
       
        //n-1 coz we dont need to calculate top stair cost
        for(int i = 2 ; i<n ; i++){
            dp[i] = min(dp[i-1], dp[i-2]) + cost[i] ;
        }

        //
        return min(dp[n-1] , dp[n-2]) ;
    }*/

    int solve(vector<int>& cost , int n ){

        int prev2 = cost[0] ;
        int prev1 = cost[1] ;
        int curr ;
        //n-1 coz we dont need to calculate top stair cost
        for(int i = 2 ; i<n ; i++){
            curr = min(prev1 , prev2) + cost[i] ;
            
            //shift
            prev2 = prev1 ;
            prev1 = curr ;
        }

        //
        return min(prev1 , prev2) ;
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int> dp(n , -1) ;
        //nth case for top stair to go back as we are not going to consider cost of top (nth) stair
        return solve(cost , n ) ;
    }
};



//another way to handle nth stair case with single formula 

class Solution {
public:
    int solve(vector<int>& cost , int n , vector<int> &dp){
        //base case
        if(n == 0){
            return cost[0] ;
        }
        
        if(n == 1){
            return cost[1] ;
        }
        
        if(dp[n] != -1){
            return dp[n] ;
        }
        
        //last stair chya pudhe nhi jaych so tikd cha cost add nhi consider honar nd dila hi nhi 
        int costToAdd = 0 ;
        if(n != cost.size()){
            costToAdd = cost[n] ;
        }
        
        dp[n] = min(solve(cost , n-1 , dp) , solve(cost , n-2 , dp)) + costToAdd ;
        
        return dp[n] ;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;
        vector<int> dp(n+1 , -1) ;
        //ans for n
        return solve(cost , n , dp) ;
    }
};