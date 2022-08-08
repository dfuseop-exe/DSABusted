int solve(int n, vector<int> days, vector<int> cost ,int index ,vector<int> &dp){
    //base case
    if(index >=  n){
        return 0 ;
    }
    
    if(dp[index]  != -1){
        return dp[index] ;
    }
    
    //one Day pass
    int forOneDay = cost[0] + solve(n , days , cost , index+1 ,dp) ;
    
    //seven Days pass
    //traverse index to 8th day as we use this pass for 7 days
    int i ;
    for(i = 0 ; i < n && days[i] < days[index] + 7 ; i++);
    
    int forSevenDay = cost[1] + solve(n , days , cost , i ,dp) ;
    
    
    //30 Days pass
    //traverse index to 8th day as we use this pass for 7 days
    for(i = 0 ; i < n && days[i] < days[index] + 30 ; i++);
    
    int forthirtyDay = cost[2] + solve(n , days , cost , i , dp) ;
    
    
    dp[index] = min(forOneDay , min(forSevenDay , forthirtyDay)) ; ;
    return dp[index] ;
}
int minimumCoins(int n, vector<int> days, vector<int> cost){
    vector<int> dp(n+1 , -1) ;
    return solve(n,days,cost,0 , dp) ;
}


//bottom up approach

class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs){
        vector<int> dp(days.size()+1) ;
        dp[days.size()] = 0 ;

        
        for(int k = days.size()-1 ; k >= 0 ; k--){
            int option1 = costs[0] + dp[k+1];
            int i ;
            for(i = 0 ; i < days.size() && days[i] < days[k] + 7 ; i++);
            int option2 = costs[1] + dp[i] ;
            for(i = 0 ; i < days.size() && days[i] < days[k] + 30 ; i++);
            int option3 = costs[2] + dp[i] ;

            dp[k] = min(option1 , min(option2 , option3)) ;
        }
        
        return dp[0] ;
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return solve(days,costs) ;
    }
};